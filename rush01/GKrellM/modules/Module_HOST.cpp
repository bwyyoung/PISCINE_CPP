/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_HOST.cpp                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:45 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/07 18:29:45 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_HOST.hpp"



Module_HOST::Module_HOST(void) :
		IMonitorModule(MODULE_HOST, MODULE_TYPE_SMALL), _strings()
{
	char		buffer[100];

	this->_strings.resize(3);
	this->_strings[0] = MODULE_HOST;
	this->_strings[1] = "   ";
	buffer[0] = '\0';
	if (gethostname(buffer, sizeof(buffer) - 1) != 0)
		this->_strings[2] = "error...";
	else
		this->_strings[2] = buffer;
}


Module_HOST::~Module_HOST() {}


std::vector<std::string> const	&Module_HOST::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_HOST::getNumbers(void) const
{return (this->_numbers);}

std::string const			&Module_HOST::getModuleName(void) const
{return (this->_moduleName);}

void						Module_HOST::refresh_datas(void)
{
	this->refresh_render_data(this->_strings);
}

