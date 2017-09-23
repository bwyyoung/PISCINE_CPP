/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  memoryquery.hpp                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef PISCINE_C_MEMORYQUERY_HPP
#define PISCINE_C_MEMORYQUERY_HPP

#include "cpuquery.hpp"
#include <stdlib.h>
#include <stdio.h>

/** @brief General querying memory/RAM data class
*/
class MemoryQuery
{
public :
	/// Constructor
	MemoryQuery();
	~MemoryQuery();
	/**
	  @brief Returns the system total memory
	  @return float, the size of the system memory, the unit is defined by
				memory unit attribute, you can set it with the setter function
				setMemoryUnit(memoryUnit unit);
	*/
	float getTotalMem();

	/**
	  @brief Returns the system used memory
	  @return float, the size of the system memory, the unit is defined by
				memory unit attribute, you can set it with the setter function
				setMemoryUnit(memoryUnit unit);
	*/
	float getUsedMem();
	/**
	  @brief Returns the system free memory
	  @return float, the size of the system memory, the unit is defined by
				memory unit attribute, you can set it with the setter function
				setMemoryUnit(memoryUnit unit);
	*/
	float getFreeMemory();
	/**
	  @brief Returns the system used memory
	  @return float, a percentage of the used memory
	*/
	float getMemoryUsage();
	const std::vector<float>& getMemoryUsageCache();
	/**
	  @brief Returns the system used memory percentages ad a cache,
			cache is not ordered
	  @param cache : the cache to be filled, dont worry about the size,
					cache is gonna be riesized to fit
	  @return , the size of the cache is defined internally
	*/
	void getOrderedMemoryUsageCache(std::vector<float>  &cache);

private:
	/**
	  @brief This procedure reorders a cache
	  @param source : the source cache to be reordered
	  @param target : where to put the ordered cache , the operation is not in
	  place means the source is not modified
*/
	void reorderCache(std::vector<float> &source, std::vector<float> &target);

	/// Define wheter to use mega or gigabye for the memory size,
	/// default of the class is GIGA_BYTE
	enum memoryUnit
	{
		MEGA_BYTE = 0,
		GIGA_BYTE = 1
	};
private:
	/// Megabyte size used internally
	static const long MEGA_BYTE_MULT = 1048576;
	/// Gigabyte size used internally
	static const long GIGA_BYTE_MULT = 1073741824;
	/**
	  @brief This procedure returns the memory converted based
	  on the setting of the class
	  */
	float convertMemory( long bytes);
	/// Current internal memory unit
	memoryUnit m_memoryUnit;
	/// Attribute holding the size of the internal cache
	int m_cacheSize;
	/// Attribute holding the start index of the cache
	int m_cacheStartIndex;
	std::vector<float> m_cache;
	MemoryQuery(MemoryQuery const &src);
	MemoryQuery		&operator=(MemoryQuery const &rhs);
};

#endif //PISCINE_C_MEMORYQUERY_HPP
