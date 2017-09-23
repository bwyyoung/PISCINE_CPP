/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_writecell.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_writecell.hpp"
#include "mindopen.hpp"

cmd_writecell::cmd_writecell() : I_Instruction(CMD_WRITECELL)
{

}

cmd_writecell::~cmd_writecell() {}

cmd_writecell::cmd_writecell(cmd_writecell const& rhs) : I_Instruction(CMD_WRITECELL)
{
	static_cast<void>(rhs);
	return ;
}

cmd_writecell&			cmd_writecell::operator=(cmd_writecell const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

void					cmd_writecell::execute(int &cell_index, int &cell, int &instruction_index)
{
	UNUSED(cell_index);
	UNUSED(instruction_index);
	if (Mindopen::getInstance()->file_input_enabled())
		cell = Mindopen::getInstance()->get_input();
	else if (DEBUG_CIN_CELL_WRITE)
		cell = std::getchar();
}