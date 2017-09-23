/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_DISK.cpp                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:45 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/12 11:22:20 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_DISK.hpp"

std::string					Module_DISK::datas[2] = {"", ""};


Module_DISK::Module_DISK(void) :
		IMonitorModule(MODULE_DISK, MODULE_TYPE_SMALL), _strings()
{
	this->_strings.push_back(MODULE_DISK);
	this->_strings.push_back("");
	this->_strings.push_back("DATA");
	this->_strings.push_back("");
	this->_strings.push_back("");
}

void						Module_DISK::update_data(std::string *array)
{
	this->datas[0] = array[0];
	this->datas[1] = array[1];
}


Module_DISK::~Module_DISK() {}


std::vector<std::string> const	&Module_DISK::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_DISK::getNumbers(void) const
{return (this->_numbers);}

std::string const			&Module_DISK::getModuleName(void) const
{return (this->_moduleName);}




void						Module_DISK::refresh_datas(void)
{
	this->_strings[3] = "read: " + Module_DISK::datas[0];
	this->_strings[4] = "write: " + Module_DISK::datas[1];
	this->refresh_render_data(this->_strings);
}
