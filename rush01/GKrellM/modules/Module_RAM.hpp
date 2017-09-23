/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_RAM.hpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:53 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/19 11:09:50 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef Module_RAM_HPP
# define Module_RAM_HPP

# include "IMonitorModule.hpp"

class Module_RAM : public IMonitorModule
{
public:
	Module_RAM(void);
	virtual ~Module_RAM();


	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<double> const		&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	void							update_data(std::string *array);
	std::string*					getDatas();
private:
	static std::string			datas[4];
	Module_RAM(Module_RAM const &src);
	Module_RAM					&operator=(Module_RAM const &rhs);

	std::vector<std::string>	_strings;

	std::deque<double>			_numbers;

	double						_maxRAM;
	
};

#endif
