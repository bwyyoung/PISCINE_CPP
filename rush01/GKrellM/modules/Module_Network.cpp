/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_Network.cpp                                 :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:45 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/12 11:27:54 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_Network.hpp"

std::string					Module_Network::datas[2] = {"", ""};


Module_Network::Module_Network(void) :
		IMonitorModule(MODULE_NETWORK, MODULE_TYPE_SMALL), _strings()
{
	this->_strings.push_back(MODULE_NETWORK);
	this->_strings.push_back("");
	this->_strings.push_back("PACKETS");
	this->_strings.push_back("");
	this->_strings.push_back("");
}

void						Module_Network::update_data(std::string *array)
{
	this->datas[0] = array[0];
	this->datas[1] = array[1];
}

Module_Network::~Module_Network() {}

std::vector<std::string> const	&Module_Network::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_Network::getNumbers(void) const
{return (this->_numbers);}

std::string const				&Module_Network::getModuleName(void) const
{return (this->_moduleName);}


void						Module_Network::refresh_datas(void)
{
	this->_strings[3] = "in: " + Module_Network::datas[0];
	this->_strings[4] = "out: " + Module_Network::datas[1];
	this->refresh_render_data(this->_strings);
}
