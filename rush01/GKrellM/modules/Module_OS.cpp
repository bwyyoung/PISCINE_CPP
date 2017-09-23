/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_OS.cpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:45 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/19 16:29:01 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_OS.hpp"
#include <sys/sysctl.h>
#include <sys/types.h>


Module_OS::Module_OS(void) :
		IMonitorModule(MODULE_OS, MODULE_TYPE_SMALL), _strings()
{
	this->_strings.push_back(MODULE_OS);
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
}


Module_OS::~Module_OS() {}




std::vector<std::string> const	&Module_OS::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_OS::getNumbers(void) const
{return (this->_numbers);}

std::string const				&Module_OS::getModuleName(void) const
{return (this->_moduleName);}


void						Module_OS::refresh_datas(void)
{
	char	kernostype[100];
	char	kernosrelease[100];
	size_t	size = 100;

	sysctlbyname("kern.ostype", &kernostype, &size, NULL, 0);
	sysctlbyname("kern.osrelease", &kernosrelease, &size, NULL, 0);
	this->_strings[2] = "Type: ";
	this->_strings[2] += kernostype;
	this->_strings[3] = "Release: ";
	this->_strings[3] += kernosrelease;
	this->refresh_render_data(this->_strings);
}