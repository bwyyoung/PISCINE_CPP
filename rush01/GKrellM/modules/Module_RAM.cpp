/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_RAM.cpp                                     :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/04 15:40:35 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/19 11:14:01 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_RAM.hpp"


std::string					Module_RAM::datas[4] = {"","",""};

#define GB_1 1073741.2740f

Module_RAM::Module_RAM(void) :
		IMonitorModule(MODULE_RAM, MODULE_TYPE_SMALL), _strings()
{
	int64_t bytes;
	size_t len = sizeof(bytes);
	size_t				pos;
	std::stringstream	ram;
	
	this->_strings.push_back(MODULE_RAM);
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	sysctlbyname("hw.memsize", &bytes, &len, NULL, 0);
	bytes /= 1024;
	bytes /= 1024;
	int megs = static_cast<int>(bytes);
	ram << megs << "M";
	datas[3] = std::to_string(megs);
	this->_strings[2] = "Capacity: " + ram.str();
	pos = ram.str().find_first_of("0123456789.");
	this->_maxRAM = std::atof(
		ram.str().substr(pos, ram.str().find_last_of("0123456789.") - pos + 1
			).c_str()) + 1000.;
	this->_numbers.push_back(0.f);
	_moduleName = MODULE_RAM;
}

void								Module_RAM::update_data(std::string *array)
{
	this->datas[0] = array[0];
	this->datas[1] = array[1];
	this->datas[2] = array[2];
}

std::string*						Module_RAM::getDatas()
{
	return this->datas;
}

Module_RAM::~Module_RAM() {}


std::vector<std::string> const		&Module_RAM::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_RAM::getNumbers(void) const
{return (this->_numbers);}

std::string const			&Module_RAM::getModuleName(void) const
{return (this->_moduleName);}




void						Module_RAM::refresh_datas(void)
{
	size_t          pos = Module_RAM::datas[0].find_first_of("0123456789.");
	double           nb = std::atof(
		Module_RAM::datas[0].substr(
			pos, Module_RAM::datas[0].find_last_of("0123456789.") - pos + 1
			).c_str());

	if (!isnan(nb) && nb > 0.f && nb < _maxRAM )
	{
		this->_numbers.push_back(nb / _maxRAM);
		if (this->_numbers.size() > 60)
			this->_numbers.pop_front();
	}
	this->_strings[3] = "Used: " + Module_RAM::datas[0] + "M";
	this->_strings[4] = "Wired: " + Module_RAM::datas[1]+ "M";
	this->_strings[5] = "Unused: " + Module_RAM::datas[2]+ "M";
	this->refresh_render_data(this->_strings);
}

