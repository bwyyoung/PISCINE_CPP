/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  cpuquery.hpp                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef CPUQUERY
#define CPUQUERY

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <vector>

# define UNUSED(x)				static_cast<void>(x)

/** @brief General querying cpus data class
*/

class CpuQuery
{
public:
	/**
	This is the constructor
	*/
	CpuQuery();
	~CpuQuery();
	/**
	This procedure parse the "/proc/stat" file
	to query the cpu data, then you can query the
	the data stored internally in the class with one
	of the method below
	*/
	void getCPUs();

	/**
	*This procedrue get the instant cpu usage of the cpu index
	*provided
	*@param coreIDx : the index of the cpu you want to query,
	*				it ranges from zero to numberOfCores included
	*				where the zero index is an average of all cpus.\n
	*			   Example : if you have an 8 core cpu in order to get
	*			   the value for the 8th cpu you need to query for the
	*			   8 index and not the 7th as you might have expected
	*@param cache : where to store the data, the cache is dinamically resized
	*			  to a 1D matrix with one row and number of columns equal to the
	*			  private attribute m_cacheSize
	*/
	void getInstantCPU(const int &coreIDx ,
					   std::vector<std::vector<float> > &cache);
	/** This procedure returns a vector containing the cache for the given cpu
	  * index
	  * @param coreIDx : which core to query
	*/
	const std::vector<float>& getCpuCache(const int &coreIDx);

	/**
	  * This procedure gets an ordered cpu for the given core index
	  * the cache internally is not ordered, in order to save in memory copies
	  * the start index of the cache is looping trough the lenght of the cache
	  * meaning that when you acces the data , the start of the cache wont be at
	  * index 0.
	  * This procedure reoders the cache and stores it in the provided vector
	  * @param coreIDx : which core to query
	  * @param cache : the structure in which to store the data
	  */
	void  getOrderedCpuCache(const int &coreIDx , std::vector<std::vector<float> > &cache );

	/**
	  *This procedure gathers all the ordered caches for all cpus
	  * @param cache : the structure in which to store the data
	  */
	void  getOrderedCpusCache( std::vector<std::vector<float> > &cache );

	/**
	  *This procedure generate a 1D matrix with all the current cpu value,
	  * it wont generate a cache but only istant value, the structure of
	  * the data will be as many columns as cores + 1 and one row
	  * @param cache : the structure in which to store the data
	  */
	void getAllInstantCPUs(std::vector<std::vector<float> > &cache);

	/**
	 * This procedure returns the number of core of our cpu
	 * @return int : The number of cores
	 */
	int getNumberOfCores();
	CpuQuery(CpuQuery const &src);
private :
	/** This procedure reorders an input cache into the target cache
	  * The two data structure should have the same size
	  * no check performed internally so far
	* @param souce : the source data to reorder
	* @param target : the target structure in which we will store the re-ordered
					  data
	*/
	void reorderCache( std::vector<float> &source,
					   std::vector<float> &target);


	/// Internal variable storing the number of cores
	int m_numberOfCores;
	/// Working variable used to store the percentage of the core
	float m_percent;
	int m_totalUser;
	int m_totalUserLow;
	int m_totalSys;
	int m_totalIdle;

	/// Internal working data holding the cache for partial core usage
	std::vector<int>m_lastTotalUser;
	std::vector<int>m_lastTotalUserLow;
	std::vector<int>m_lastTotalSys;
	std::vector<int>m_lastTotalIdle;

	/// Internal working variable
	std::string m_tempStr;
	int i;

	/// Attribute holding the size of the internal cache
	int m_cacheSize;
	/// Attribute holding the start index of the cache
	int m_cacheStartIndex;
	/// Internal 2D matrix holding all the percentage computed (up to cache size)
	std::vector<std::vector<float> >m_percentages;

	CpuQuery		&operator=(CpuQuery const &rhs);


};


#endif // QUERYRESOURSCE_H




