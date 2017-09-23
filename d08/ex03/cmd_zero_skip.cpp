/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_zero_skip.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_zero_skip.hpp"

cmd_zero_skip::cmd_zero_skip() : I_Instruction(CMD_ZERO_SKIP)
{

}

cmd_zero_skip::~cmd_zero_skip() {}

cmd_zero_skip::cmd_zero_skip(cmd_zero_skip const& rhs) : I_Instruction(CMD_ZERO_SKIP)
{
	static_cast<void>(rhs);
	return ;
}

cmd_zero_skip&			cmd_zero_skip::operator=(cmd_zero_skip const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

void					cmd_zero_skip::execute(int &cell_index, int &cell, int &instruction_index)
{
	UNUSED(cell_index);
	if (cell == 0)
		instruction_index = partner_index - 1; //for upper while loop to increment
}