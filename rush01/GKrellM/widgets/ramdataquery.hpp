/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  ramdataquery.hpp                                   :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */


#ifndef RAMDATAQUERY_H
#define RAMDATAQUERY_H

#include "memoryquery.hpp"
#include "dataquery.hpp"

/**
  @brief This class is used to query the ram data for the performance widge
 */

class RamDataQuery : public DataQuery
{
public:
	/// The constructor
	RamDataQuery();
	/// The destructor
	~RamDataQuery();
	/// This function gather all the data needed and stores it internally in the
	/// cache attribute
	void getData();
	RamDataQuery(RamDataQuery const &src);
private :
	/// The class used for general memory query
	MemoryQuery m_mem;
	RamDataQuery		&operator=(RamDataQuery const &rhs);
};


#endif // RAMDATAQUERY_H
