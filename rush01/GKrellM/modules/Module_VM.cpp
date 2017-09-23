/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_VM.cpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/04 15:35:11 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/19 14:09:12 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_VM.hpp"

std::string					Module_VM::datas[4] = {"", "", "", ""};


Module_VM::Module_VM(void) :
	IMonitorModule(MODULE_VM, MODULE_TYPE_SMALL), _strings()
{
	this->_strings.push_back(MODULE_VM);
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
}

Module_VM::~Module_VM() {}

std::vector<std::string> const	&Module_VM::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_VM::getNumbers(void) const
{return (this->_numbers);}

std::string const			&Module_VM::getModuleName(void) const
{return (this->_moduleName);}

void						Module_VM::refresh_datas(void)
{
	this->_strings[2] = Module_VM::datas[0];
	this->_strings[3] = Module_VM::datas[1];
	this->_strings[4] = Module_VM::datas[2];
	this->_strings[5] = Module_VM::datas[3];
	this->refresh_render_data(this->_strings);
}

void						Module_VM::update_data(std::string *array)
{
	this->datas[0] = array[0];
	this->datas[1] = array[1];
	this->datas[2] = array[2];
	this->datas[3] = array[3];
}

