/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  cpudataquery.hpp                                   :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef CPUDATAQUERY_H
#define CPUDATAQUERY_H
#include "dataquery.hpp"
#include "cpuquery.hpp"

/** @brief This class is used to read cpu data for the widget
  *
  * This class subclass DataQuery absatract class, it specialize it in order
  * to read the cpu data.
  * This class performs different queryies based on two values sets in the class
  * which are L
  * \li index : defines which cpu to read if multi is off , ranges for the number
				of cores
  * \li multi : If set to on it will generate data for all the different cores plus
				the average of the cpus
				Meaning if set to on the size of the  cache will be numberOfCores +1
				the average cpus is stored at index 0
  */

class CpuDataQuery : public DataQuery
{
public:
	/// The constructor
	CpuDataQuery();
	/// The destructor
	~CpuDataQuery();
	/// This function gather all the data needed and stores it internally in the
	/// cache attribute
	void getData();
	/**
	 * @brief This procedure returns the number of cores
	 * @return int, number of cores
	 */
	int getNumberOfCores();
	CpuDataQuery(CpuDataQuery const &src);
private :
	/// The class used for general cpu query
	CpuQuery m_cpu;

	CpuDataQuery		&operator=(CpuDataQuery const &rhs);
};

#endif // CPUDATAQUERY_H
