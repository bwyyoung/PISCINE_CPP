/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  dataquery.cpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "dataquery.hpp"

DataQuery::DataQuery():m_index(0), m_multi(0)
{
}



void DataQuery::setIndex(int index)
{

	m_index = index;

}

void DataQuery::setMulti( bool value)
{
	m_multi = value;
}

std::vector<std::vector<float> > DataQuery::get_cache()
{
	return this->m_cache;
}