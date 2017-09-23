/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_CAT.cpp                                     :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:45 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/17 09:01:30 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */


#include "Module_CAT.hpp"

Module_CAT::Module_CAT(void) :
		IMonitorModule(MODULE_CAT, MODULE_TYPE_LARGE), _strings()
{
	this->_strings.resize(9);
	this->_strings[0]  = MODULE_CAT;
	this->_strings[1]  = "           ";
	this->_strings[2]  = "  |\\_._/|  ";
	this->_strings[3]  = "  | o o |  ";
	this->_strings[4]  = "  (  T  )  ";
	this->_strings[5]  = " .^`-^-'^. ";
	this->_strings[6]  = " `.  ;  .' ";
	this->_strings[7]  = " | | | | | ";
	this->_strings[8]  = "((_((|))_))";

}

Module_CAT::~Module_CAT() {}


std::vector<std::string> const	&Module_CAT::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_CAT::getNumbers(void) const
{return (this->_numbers);}


std::string const			&Module_CAT::getModuleName(void) const
{return (this->_moduleName);}




void						Module_CAT::refresh_datas(void)
{
	int		random = std::rand() % 4;
	if (random == 0 || random == 2)
	{
		this->_strings[2]  = "  |\\_._/|  ";
		this->_strings[3]  = "  | o o |  ";
		this->_strings[4]  = "  (  T  )  ";
	}
	else if (random == 1)
	{
		this->_strings[2]  = "  |,\\__/|  ";
		this->_strings[3]  = "  |  o o|  ";
		this->_strings[4]  = "  (   T )  ";
	}
	else
	{
		this->_strings[2]  = "  |\\__/,|  ";
		this->_strings[3]  = "  |o o  |  ";
		this->_strings[4]  = "  ( T   )  ";
	}
	this->refresh_render_data(this->_strings);
}
