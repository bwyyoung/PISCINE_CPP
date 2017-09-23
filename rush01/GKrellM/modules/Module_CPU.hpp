/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_CPU.hpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/04 15:35:01 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/18 15:31:54 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include "IMonitorModule.hpp"

class Module_CPU : public IMonitorModule
{
public:
	Module_CPU(void);
	virtual ~Module_CPU();

	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<double> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	void							update_data(std::string *array);
	std::string*					getDatas();
protected:
private:
	static std::string			datas[3];
	Module_CPU(Module_CPU const &src);
	Module_CPU					&operator=(Module_CPU const &rhs);
	std::vector<std::string>	_strings;
	std::deque<double>			_numbers;
	
};
#endif
