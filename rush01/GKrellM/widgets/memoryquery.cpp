/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  memoryquery.cpp                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "memoryquery.hpp"
#include "../MGR_Module.hpp"
#include "../modules/Module_RAM.hpp"

MemoryQuery::~MemoryQuery() {}

MemoryQuery::MemoryQuery(MemoryQuery const& rhs)
{
	UNUSED(rhs);
	return ;
}

MemoryQuery&		MemoryQuery::operator=(MemoryQuery const & rhs)
{
	UNUSED(rhs);
	return (*this);
}

MemoryQuery::MemoryQuery() : m_memoryUnit(GIGA_BYTE) ,
							 m_cacheSize(30),
							 m_cacheStartIndex(0)
{
	m_cache.resize(m_cacheSize);
}

float MemoryQuery::getTotalMem()
{
	char	word[256];
	IMonitorModule* RAM = MGR_Module::getInstance()->get_module(MODULE_RAM);
	if (!RAM)
		return 0;
	std::memcpy(word, RAM->getDatas()[3].c_str(), RAM->getDatas()[3].length());
	long num = std::strtol(word, NULL, 0);
	return convertMemory(num);
}

float MemoryQuery::getUsedMem()
{
	char	word[256];
	IMonitorModule* RAM = MGR_Module::getInstance()->get_module(MODULE_RAM);
	if (!RAM)
		return 0;
	std::memcpy(word, RAM->getDatas()[0].c_str(), RAM->getDatas()[0].length());
	long num = std::strtol(word, NULL, 0);
	return convertMemory(num);
}


float MemoryQuery::getFreeMemory()
{
	char	word[256];
	IMonitorModule* RAM = MGR_Module::getInstance()->get_module(MODULE_RAM);
	if (!RAM)
		return 0;
	std::memcpy(word, RAM->getDatas()[2].c_str(), RAM->getDatas()[2].length());
	long num = std::strtol(word, NULL, 0);
	return convertMemory(num);
}

float MemoryQuery::getMemoryUsage()
{
	float percentage = float(getUsedMem())/getTotalMem()*100.0f;
	int currCacheIndex = m_cacheStartIndex-1;
	if (currCacheIndex < 0)
	{
		currCacheIndex = m_cacheSize -1;
	}
	m_cache[currCacheIndex] =   percentage;

	//loop the cache index
	m_cacheStartIndex++;
	if ( m_cacheStartIndex > (m_cacheSize -1))
	{
		m_cacheStartIndex = 0;
	}
	return percentage;
}

float MemoryQuery::convertMemory( long bytes)
{
	float toReturn = 0;
	switch(m_memoryUnit)
	{
		case 0 :

			toReturn= float(bytes)/MEGA_BYTE_MULT;
			break;
		case 1 :
			toReturn= float(bytes)/GIGA_BYTE_MULT;
			break;
	}
	return toReturn;
}


const std::vector<float>&  MemoryQuery::getMemoryUsageCache()
{
	return m_cache;
}

void MemoryQuery::getOrderedMemoryUsageCache(std::vector<float>  &cache)
{
	cache.resize(m_cacheSize);
	reorderCache(m_cache , cache);
}

void MemoryQuery::reorderCache(std::vector<float> &source, std::vector<float> &target)
{
	//let s make a copy of the internal start index so we can use it to loop it
	int tempIndex = int(m_cacheStartIndex)-1;
	//loop cache size
	for (int i =0 ; i < m_cacheSize ;i++)
	{
		target[i]= source[tempIndex];
		tempIndex ++;
		if ( tempIndex > (m_cacheSize-1 ))
		{
			tempIndex = 0;
		}
	}
}