/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mvforward.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_mvforward.hpp"

cmd_mvforward::cmd_mvforward() : I_Instruction(CMD_MVFORWARD)
{

}

cmd_mvforward::~cmd_mvforward() {}

cmd_mvforward::cmd_mvforward(cmd_mvforward const& rhs) : I_Instruction(CMD_MVFORWARD)
{
	static_cast<void>(rhs);
	return ;
}

cmd_mvforward&			cmd_mvforward::operator=(cmd_mvforward const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

void					cmd_mvforward::execute(int &cell_index, int &cell, int &instruction_index)
{
	UNUSED(cell);
	UNUSED(instruction_index);
	cell_index += 1;
}
