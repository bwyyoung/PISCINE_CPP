/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_Network.hpp                                 :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:53 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/12 11:02:00 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include <vector>
# include "IMonitorModule.hpp"

class Module_Network : public IMonitorModule
{
public:
	Module_Network(void);
	virtual ~Module_Network();


	void							refresh_datas(void);
	std::vector<std::string> const	&getStrings(void) const;
	std::deque<double> const			&getNumbers(void) const;
	std::string const				&getModuleName(void) const;
	void							update_data(std::string *array);
protected:
private:
	static std::string          datas[2];
	Module_Network(Module_Network const &src);
	Module_Network					&operator=(Module_Network const &rhs);

	std::vector<std::string>	_strings;

	std::deque<double>			_numbers;
	
};
#endif
