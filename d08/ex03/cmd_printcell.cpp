/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_printcell.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_printcell.hpp"

cmd_printcell::cmd_printcell() : I_Instruction(CMD_PRINTCELL)
{

}

cmd_printcell::~cmd_printcell() {}

cmd_printcell::cmd_printcell(cmd_printcell const& rhs) : I_Instruction(CMD_PRINTCELL)
{
	static_cast<void>(rhs);
	return ;
}

cmd_printcell&			cmd_printcell::operator=(cmd_printcell const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

void					cmd_printcell::execute(int &cell_index, int &cell, int &instruction_index)
{
	UNUSED(cell_index);
	UNUSED(instruction_index);
	char			output = static_cast<char>(cell);
	std::string		str(1, output);
	if (DEBUG_COUT_CELL_PRINT)
		std::cout << str;
}