/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_CPU.cpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/04 15:35:11 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/19 11:09:23 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_CPU.hpp"

std::string					Module_CPU::datas[3] = {"", "", ""};

Module_CPU::Module_CPU(void) :
		IMonitorModule(MODULE_CPU, MODULE_TYPE_SMALL), _strings(), _numbers(0)
{
	char			buf[100];
	size_t			buflen = 100;
	size_t			pos;

	this->_strings.resize(4);
	this->_strings[0] = MODULE_CPU;
	this->_strings[1] = "";
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
	pos = buflen;
	this->_strings[2].assign(buf, pos);
	pos = this->_strings[2].find(" ", this->_strings[2].find(" ") + 1);
	this->_strings[3].assign(this->_strings[2], pos + 1, buflen - pos - 2);
	this->_strings[2].resize(pos);
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_strings.push_back("");
	this->_numbers.push_back(0.f);

}
void						Module_CPU::update_data(std::string *array)
{
	this->datas[0] = array[0];
	this->datas[1] = array[1];
	this->datas[2] = array[2];
}

std::string*					Module_CPU::getDatas()
{
	return this->datas;
}


Module_CPU::~Module_CPU() {}


std::vector<std::string> const	&Module_CPU::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_CPU::getNumbers(void) const
{return (this->_numbers);}

std::string const			&Module_CPU::getModuleName(void) const
{return (this->_moduleName);}




void						Module_CPU::refresh_datas(void)
{
	size_t			pos = Module_CPU::datas[1].find_first_of("0123456789.");
	double			nb = atof(Module_CPU::datas[1].substr(
	pos, Module_CPU::datas[1].find_last_of("0123456789.") - pos + 1).c_str());

	if (!isnan(nb) && nb > 0.0 && nb < 100.0)
	{
		this->_numbers.push_back(nb / 100.0);
		if (this->_numbers.size() > 60)
			this->_numbers.pop_front();
	}
	this->_strings[4] = "user: " + Module_CPU::datas[0];
	this->_strings[5] = "system: " + Module_CPU::datas[1];
	this->_strings[6] = "idle: " + Module_CPU::datas[2];
	this->refresh_render_data(this->_strings);
}

