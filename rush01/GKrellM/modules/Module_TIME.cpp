/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_TIME.cpp                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:45 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/07 18:33:06 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_TIME.hpp"

Module_TIME::Module_TIME(void) :
		IMonitorModule(MODULE_TIME, MODULE_TYPE_SMALL), _strings()
{
	this->_strings.resize(4);
	this->_strings[0]  = MODULE_TIME;
	this->_strings[1]  = "           ";
}

Module_TIME::~Module_TIME() {}

std::vector<std::string> const	&Module_TIME::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_TIME::getNumbers(void) const
{return (this->_numbers);}

std::string const				&Module_TIME::getModuleName(void) const
{return (this->_moduleName);}

void							Module_TIME::refresh_datas(void)
{
	time_t		t;
	char		buffer[100];
	size_t		ret;

	time(&t);
	ret = std::strftime(buffer, sizeof(buffer) - 1, "%a %d %b %y",
						localtime(&t));
	this->_strings[2].assign(buffer, ret);
	std::strftime(buffer, sizeof(buffer) - 1, "%r", localtime(&t));
	this->_strings[3].assign(buffer, ret - 2);
	this->refresh_render_data(this->_strings);
}

void						Module_TIME::update_data(std::string *array)
{
	UNUSED(array);
}
