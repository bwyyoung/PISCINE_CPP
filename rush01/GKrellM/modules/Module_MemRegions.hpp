/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_MemRegions.hpp                              :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/04 15:35:01 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/15 15:00:25 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef MEMREGIONSMODULE_HPP
# define MEMREGIONSMODULE_HPP

# include "IMonitorModule.hpp"

class Module_MemRegions : public IMonitorModule
{
public:
	Module_MemRegions(void);
	virtual ~Module_MemRegions();


	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<double> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	void							update_data(std::string *array);
protected:
private:
	static std::string          datas[3];

	Module_MemRegions(Module_MemRegions const &src);
	Module_MemRegions					&operator=(Module_MemRegions const &rhs);

	std::vector<std::string>	_strings;

	std::deque<double>			_numbers;
	
};

#endif
