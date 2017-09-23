/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_TIME.hpp                                     :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:53 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:00:52 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include "IMonitorModule.hpp"

class Module_TIME : public IMonitorModule
{
public:
	Module_TIME(void);
	virtual ~Module_TIME();
	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<double> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	void							update_data(std::string *array);
protected:
private:
	Module_TIME(Module_TIME const &src);
	Module_TIME					&operator=(Module_TIME const &rhs);

	std::vector<std::string>	_strings;

	std::deque<double>			_numbers;
	
};

#endif
