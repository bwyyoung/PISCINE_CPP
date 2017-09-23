/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_VM.hpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/04 15:35:01 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/19 14:05:05 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef VMMODULE_HPP
# define VMMODULE_HPP

# include "IMonitorModule.hpp"

class Module_VM : public IMonitorModule
{
public:
	Module_VM(void);
	virtual ~Module_VM();
	void						refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<double> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	void							update_data(std::string *array);
protected:
private:
	static std::string			datas[4];
	Module_VM(Module_VM const &src);
	Module_VM					&operator=(Module_VM const &rhs);

	std::vector<std::string>	_strings;

	std::deque<double>			_numbers;
	
};

#endif
