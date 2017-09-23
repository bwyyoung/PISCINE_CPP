/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  ramdataquery.cpp                                   :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "ramdataquery.hpp"

RamDataQuery::RamDataQuery()
{
	m_cache.resize(1);
}


void RamDataQuery::getData()
{
	//Update the data in the cache , this function also returns
	//the instant memory usage but we discard it since we actually
	// need the cache
	m_mem.getMemoryUsage();
	//Get the ordered data
	m_mem.getOrderedMemoryUsageCache(m_cache[0]);

}

RamDataQuery::~RamDataQuery() {}

RamDataQuery::RamDataQuery(RamDataQuery const& rhs)
{
	UNUSED(rhs);
	return ;
}

RamDataQuery&		RamDataQuery::operator=(RamDataQuery const & rhs)
{
	UNUSED(rhs);
	return (*this);
}

