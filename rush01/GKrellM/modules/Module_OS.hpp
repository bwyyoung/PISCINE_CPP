/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_OS.hpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:53 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 15:38:49 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

# include "IMonitorModule.hpp"

class Module_OS : public IMonitorModule
{
public:
	Module_OS(void);
	virtual ~Module_OS();
	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<double> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;

protected:
private:
	Module_OS(Module_OS const &src);
	Module_OS					&operator=(Module_OS const &rhs);

	std::vector<std::string>	_strings;

	std::deque<double>			_numbers;
	
};

#endif
