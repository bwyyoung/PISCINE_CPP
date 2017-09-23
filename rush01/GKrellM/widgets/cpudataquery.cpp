/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  cpudataquery.cpp                                   :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "cpudataquery.hpp"

CpuDataQuery::CpuDataQuery() : DataQuery()
{
}


void CpuDataQuery::getData()
{
	m_cpu.getCPUs();

	//if we draw a single graph we only get the cache for the
	//current cpu and store it in m_singleCache
	if (m_multi == 0)
	{
		m_cpu.getOrderedCpuCache(m_index, m_cache);
	}
	//if we draw a cache for all cpus then we grab all the cpu caches
	//and store the result in m_cache
	else
	{
		m_cpu.getOrderedCpusCache(m_cache);
	}

}


int CpuDataQuery::getNumberOfCores()
{
	return m_cpu.getNumberOfCores();

}

CpuDataQuery::~CpuDataQuery() {}

CpuDataQuery::CpuDataQuery(CpuDataQuery const& rhs)
{
	UNUSED(rhs);
	return ;
}

CpuDataQuery&		CpuDataQuery::operator=(CpuDataQuery const & rhs)
{
	UNUSED(rhs);
	return (*this);
}

