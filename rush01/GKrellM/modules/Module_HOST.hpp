/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_HOST.hpp                                 :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:53 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 15:35:23 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

# include "IMonitorModule.hpp"

class Module_HOST : public IMonitorModule
{
public:
	Module_HOST(void);
	virtual ~Module_HOST();
	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<double> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
protected:
private:
	Module_HOST(Module_HOST const &src);
	Module_HOST					&operator=(Module_HOST const &rhs);

	std::vector<std::string>	_strings;

	std::deque<double>			_numbers;
	
};

#endif
