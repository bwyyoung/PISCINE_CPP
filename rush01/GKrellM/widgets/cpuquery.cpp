/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  cpuquery.cpp                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "cpuquery.hpp"
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sstream>

#include "../MGR_Module.hpp"
#include "../modules/Module_CPU.hpp"

CpuQuery::CpuQuery():m_percent(0.0),m_cacheSize(30),
	m_cacheStartIndex(0)
{
	//Initializing number of cores
	 m_numberOfCores = sysconf(_SC_NPROCESSORS_ONLN) - 1;

	 //Initializing cache vectors
	 m_lastTotalUser = std::vector<int>(m_numberOfCores +1,0);
	 m_lastTotalUserLow = std::vector<int>(m_numberOfCores +1,0);
	 m_lastTotalSys = std::vector<int>(m_numberOfCores +1,0);
	 m_lastTotalIdle = std::vector<int>(m_numberOfCores +1,0);

	 m_percentages = std::vector<std::vector<float> >
			 (m_numberOfCores +1, std::vector<float>(m_cacheSize,0));

	 //Init data
	 getCPUs();
}



void CpuQuery::getCPUs()
{
	IMonitorModule* CPU = MGR_Module::getInstance()->get_module(MODULE_CPU);
	if (!CPU)
		return;
	int		i = 0;
	//loop the cores
	int		TOTALTIME_SINCE_BOOT;
	int		TOTALIDLE_SINCE_BOOT;
	int		TOTALUSAGE_SINCE_BOOT;
	while (i <= (m_numberOfCores))
	{
		//storing the cache index
		int currCacheIndex = m_cacheStartIndex-1;
		if (currCacheIndex < 0)
			currCacheIndex = m_cacheSize -1;
		//get the cpu name
		//Get different data usage
		if (CPU->getStrings().size() < 7)
			return ;
		m_tempStr  = CPU->getStrings()[2];
		if (CPU->getDatas()[0].empty() || CPU->getDatas()[1].empty()
				|| CPU->getDatas()[2].empty())
			return;
		m_totalUser = std::atoi(CPU->getDatas()[0].c_str());
		m_totalUserLow = std::atoi(CPU->getDatas()[0].c_str());
		m_totalSys = std::atoi(CPU->getDatas()[1].c_str());
		m_totalIdle = std::atoi(CPU->getDatas()[2].c_str());
		TOTALTIME_SINCE_BOOT = m_totalUser + m_totalUserLow + m_totalSys + m_totalIdle;
		TOTALIDLE_SINCE_BOOT = m_totalIdle;
		TOTALUSAGE_SINCE_BOOT = TOTALTIME_SINCE_BOOT - TOTALIDLE_SINCE_BOOT;
		m_percent = static_cast<float>(static_cast<float>(TOTALUSAGE_SINCE_BOOT) / static_cast<float>(TOTALTIME_SINCE_BOOT) * 100);
		m_percentages[i][currCacheIndex] = m_percent;
		//store the data in the cache for next iteration
		m_lastTotalUser[i] = m_totalUser;
		m_lastTotalUserLow[i] = m_totalUserLow;
		m_lastTotalSys[i] = m_totalSys;
		m_lastTotalIdle[i] = m_totalIdle;
		i++;
	}
	m_cacheStartIndex++;
	if ( m_cacheStartIndex > (m_cacheSize -1))
	{
		m_cacheStartIndex = 0;
	}
}

void CpuQuery::getInstantCPU(const int &coreIDx ,
							 std::vector<std::vector<float> > &cache)
{
	//resize incoming cache
	cache.resize(1);
	cache[0].resize(1);
	//store the data in the cache if ithe core idx is a valid index
	if (coreIDx <= m_numberOfCores +1)
		cache[0][0] = m_percentages[coreIDx][m_cacheStartIndex];

	else
		cache[0][0] = -1;
}

void CpuQuery::getAllInstantCPUs(std::vector<std::vector<float> > &cache)
{
	//resize incoming cache
	cache.resize(1);
	cache[0].resize(m_numberOfCores +1);
	//store correct data
	for (int i = 0; i <m_numberOfCores +1;i++)
	{
		cache[0][i] = m_percentages[i][m_cacheStartIndex];
	}


}

const std::vector<float>& CpuQuery::getCpuCache(const int &coreIDx)
{

	return m_percentages[coreIDx];

}

void CpuQuery::getOrderedCpuCache(const int &coreIDx , std::vector<std::vector<float> > &cache )
{
	//resize incoming cache
	cache.resize(1);
	cache[0].resize(m_cacheSize);
	//reorder wanted cache and store it correctly in the target cache
	reorderCache(m_percentages[coreIDx] , cache[0]);
}

void CpuQuery::getOrderedCpusCache(std::vector<std::vector<float> > &cache)
{

	//resize incoming cache
	cache.resize(m_numberOfCores +1);
	for (int j = 0 ;j < m_numberOfCores +1; j++)
	{
		cache[j].resize(m_cacheSize);
		reorderCache(m_percentages[j] , cache[j]);

	}



}

void CpuQuery::reorderCache(std::vector<float> &source, std::vector<float> &target)
{
	//let s make a copy of the internal start index so we can use it to loop it
	int tempIndex = int(m_cacheStartIndex)-1;
	//loop cache size
	for (i =0 ; i < m_cacheSize ;i++)
	{

		target[i]= source[tempIndex];
		tempIndex ++;
		if ( tempIndex > (m_cacheSize-1 ))
		{
			tempIndex = 0;
		}
	}


}

int CpuQuery::getNumberOfCores()
{
	return sysconf(_SC_NPROCESSORS_ONLN);
}




CpuQuery::~CpuQuery() {}

CpuQuery::CpuQuery(CpuQuery const& rhs)
{
	UNUSED(rhs);
	return ;
}

CpuQuery&		CpuQuery::operator=(CpuQuery const & rhs)
{
	UNUSED(rhs);
	return (*this);
}
