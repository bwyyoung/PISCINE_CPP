/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_decrement.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_decrement.hpp"
#include "mindopen.hpp"

cmd_decrement::cmd_decrement() : I_Instruction(CMD_DECREMENT)
{

}

cmd_decrement::~cmd_decrement() {}

cmd_decrement::cmd_decrement(cmd_decrement const& rhs) : I_Instruction(CMD_DECREMENT)
{
	static_cast<void>(rhs);
	return ;
}

cmd_decrement&			cmd_decrement::operator=(cmd_decrement const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

void					cmd_decrement::execute(int &cell_index, int &cell, int &instruction_index)
{
	UNUSED(cell_index);
	UNUSED(instruction_index);
	cell -= 1;
	if (cell < Mindopen::getInstance()->get_cell_lower_range())
		cell = Mindopen::getInstance()->get_cell_upper_range();
}

