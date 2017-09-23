/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_MemRegions.cpp                              :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/04 15:35:11 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/15 15:38:18 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_MemRegions.hpp"

std::string					Module_MemRegions::datas[3] = {"", "", ""};


Module_MemRegions::Module_MemRegions(void) :
		IMonitorModule(MODULE_MEMREGIONS, MODULE_TYPE_SMALL), _strings()
{
	this->_strings.push_back(MODULE_MEMREGIONS);
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
}

void						Module_MemRegions::update_data(std::string *array)
{
	this->datas[0] = array[0];
	this->datas[1] = array[1];
	this->datas[2] = array[2];
}

Module_MemRegions::~Module_MemRegions() {}


std::vector<std::string> const	&Module_MemRegions::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_MemRegions::getNumbers(void) const
{return (this->_numbers);}

std::string const			&Module_MemRegions::getModuleName(void) const
{return (this->_moduleName);}




void						Module_MemRegions::refresh_datas(void)
{
	this->_strings[2] = Module_MemRegions::datas[0];
	this->_strings[3] = Module_MemRegions::datas[1];
	this->_strings[4] = Module_MemRegions::datas[2];
	this->refresh_render_data(this->_strings);
}
