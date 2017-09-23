/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_increment.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_increment.hpp"
#include "mindopen.hpp"

cmd_increment::cmd_increment() : I_Instruction(CMD_INCREMENT)
{

}

cmd_increment::~cmd_increment() {}

cmd_increment::cmd_increment(cmd_increment const& rhs) : I_Instruction(CMD_INCREMENT)
{
	static_cast<void>(rhs);
	return ;
}

cmd_increment&			cmd_increment::operator=(cmd_increment const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

void					cmd_increment::execute(int &cell_index, int &cell, int &instruction_index)
{
	UNUSED(cell_index);
	UNUSED(instruction_index);
	cell += 1;
	if (cell > Mindopen::getInstance()->get_cell_upper_range())
		cell = Mindopen::getInstance()->get_cell_lower_range();
}
