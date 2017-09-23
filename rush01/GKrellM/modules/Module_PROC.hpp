/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_PROC.hpp                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/04 15:35:01 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/15 15:00:25 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef PROCESSESMODULE_HPP
# define PROCESSESMODULE_HPP

# include "IMonitorModule.hpp"

class Module_PROC : public IMonitorModule
{
public:
	Module_PROC(void);
	virtual ~Module_PROC();


	void							refresh_datas(void);
	std::deque<double> const			&getNumbers(void) const;
	std::vector<std::string> const	&getStrings(void) const;
	std::string const				&getModuleName(void) const;
	void							update_data(std::string *array);
protected:
private:
	static std::string				datas[3];
	Module_PROC(Module_PROC const &src);
	Module_PROC					&operator=(Module_PROC const &rhs);

	std::vector<std::string>	_strings;

	std::deque<double>			_numbers;
	
};

#endif
