/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_DISK.hpp                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:53 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/12 11:14:46 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef DISKMODULE_HPP
# define DISKMODULE_HPP

# include "IMonitorModule.hpp"

class Module_DISK : public IMonitorModule
{
public:
	Module_DISK(void);
	virtual ~Module_DISK();

	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<double> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	void							update_data(std::string *array);
protected:
private:
	static std::string          datas[2];

	Module_DISK(Module_DISK const &src);
	Module_DISK					&operator=(Module_DISK const &rhs);

	std::vector<std::string>	_strings;

	std::deque<double>			_numbers;
	
};
#endif
