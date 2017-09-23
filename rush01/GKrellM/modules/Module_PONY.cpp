/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  Module_PONY.cpp                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/03 10:00:45 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/07 18:10:20 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "Module_PONY.hpp"


Module_PONY::Module_PONY(void) :
		IMonitorModule(MODULE_PONY, MODULE_TYPE_LARGE), _strings()
{
	this->_strings.resize(30);
	this->_strings[0]  = MODULE_PONY;
	this->_strings[1]  = "           ";
	this->_strings[2]  = "                __..___ ";
	this->_strings[3]  = "          _.-'____<'``  ";
	this->_strings[4]  = "    ___.-`.-'`     ```_'";
	this->_strings[5]  = "   /  \\.'` __.----'','/.";
	this->_strings[6]  = "  ( /  \\_/` ,---''.' /  ";
	this->_strings[7]  = "  | |    `,._\\  ,'  /``'";
	this->_strings[8]  = " /( '.  .'``'-`   .-.   ";
	this->_strings[9]  = "( /\\    | |``'.`._|.-:  ";
	this->_strings[10]  = "|| (\\_  ( (    \\ _ | |  ";
	this->_strings[11]  = "|| : \\   \\ \\    ))\\ \\j  ";
	this->_strings[12]  = "|( (, \\   '.`--'/  ``-. ";
	this->_strings[13]  = "' . \\`.`.   ````  \\__/  ";
	this->_strings[14]  = " V(  \\ `-\\-,______.-'   ";
	this->_strings[15]  = "__/\\ .`.     /.^. /     ";
	this->_strings[16]  = "    \\|`.:   (/   V      ";
	this->_strings[17]  = "         `   \\          ";
	this->_strings[18]  = "              |         ";
	this->_strings[19]  = "              |         ";
	this->_strings[20]  = "              |         ";
	this->_strings[21]  = "          \\__/          ";
	this->_strings[22]  = "_____\\       \\          ";
	this->_strings[23]  = "|    |\\       \\         ";
	this->_strings[24]  = "     | `--,    \\        ";
	this->_strings[25]  = "     |   /      l       ";
	this->_strings[26]  = "      | (       |       ";
	this->_strings[27]  = "      |  \\      |       ";
	this->_strings[28]  = "       \\  `.___/        ";
	this->_strings[29]  = "\\_______)               ";
}


Module_PONY::~Module_PONY() {}


std::vector<std::string> const	&Module_PONY::getStrings(void) const
{return (this->_strings);}

std::deque<double> const			&Module_PONY::getNumbers(void) const
{return (this->_numbers);}

std::string const			&Module_PONY::getModuleName(void) const
{return (this->_moduleName);}




void						Module_PONY::refresh_datas(void)
{
	if (time(NULL) % 2 == 0)
	{
		this->_strings[9]  = "( /\\    | |``'.`._|.-:  ";
		this->_strings[10]  = "|| (\\_  ( (    \\ _ | |  ";
		this->_strings[11]  = "|| : \\   \\ \\    ))\\ \\j  ";
	}
	else
	{
		this->_strings[9]  = "( /\\    | |`*'.`._|.*:  ";
		this->_strings[10]  = "|| (\\_  ( ( *W*\\ _ |W|  ";
		this->_strings[11]  = "|| : \\   \\ \\ ** ))\\ \\j  ";
	}
	this->refresh_render_data(this->_strings);
}

