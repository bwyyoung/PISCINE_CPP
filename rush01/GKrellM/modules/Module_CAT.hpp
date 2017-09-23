/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_CAT.hpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:53 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/17 09:01:26 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef Module_CAT_HPP
# define Module_CAT_HPP

# include "IMonitorModule.hpp"

class Module_CAT : public IMonitorModule
{
public:
	Module_CAT(void);
	virtual ~Module_CAT();
	
	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<double> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
protected:
private:
	Module_CAT(Module_CAT const &src);
	Module_CAT					&operator=(Module_CAT const &rhs);

	std::vector<std::string>	_strings;
	std::deque<double>			_numbers;
	
};

#endif
