/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_PROC.cpp                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/04 15:35:11 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/15 15:38:18 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_PROC.hpp"

std::string					Module_PROC::datas[3] = {"", "", ""};


Module_PROC::Module_PROC(void) :
		IMonitorModule(MODULE_PROC, MODULE_TYPE_SMALL), _strings()
{
	this->_strings.push_back(MODULE_PROC);
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
}

void						Module_PROC::update_data(std::string *array)
{
	this->datas[0] = array[0];
	this->datas[1] = array[1];
	this->datas[2] = array[2];
}

Module_PROC::~Module_PROC() {}


std::vector<std::string> const	&Module_PROC::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_PROC::getNumbers(void) const
{return (this->_numbers);}

std::string const			&Module_PROC::getModuleName(void) const
{return (this->_moduleName);}




void						Module_PROC::refresh_datas(void)
{
	this->_strings[2] = Module_PROC::datas[0];
	this->_strings[3] = Module_PROC::datas[1];
	this->_strings[4] = Module_PROC::datas[2];
	this->refresh_render_data(this->_strings);
}