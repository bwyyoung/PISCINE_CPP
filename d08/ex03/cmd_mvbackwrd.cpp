/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mvbackwrd.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_mvbackwrd.hpp"

cmd_mvbackwrd::cmd_mvbackwrd() : I_Instruction(CMD_MVBACKWRD)
{

}

cmd_mvbackwrd::~cmd_mvbackwrd() {}

cmd_mvbackwrd::cmd_mvbackwrd(cmd_mvbackwrd const& rhs) : I_Instruction(CMD_MVBACKWRD)
{
	static_cast<void>(rhs);
	return ;
}

cmd_mvbackwrd&			cmd_mvbackwrd::operator=(cmd_mvbackwrd const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

void					cmd_mvbackwrd::execute(int &cell_index, int &cell, int &instruction_index)
{
	UNUSED(cell);
	UNUSED(instruction_index);
	cell_index -= 1;
}
