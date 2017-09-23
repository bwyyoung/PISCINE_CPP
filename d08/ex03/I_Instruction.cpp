/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   I_Instruction.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "I_Instruction.hpp"

I_Instruction::I_Instruction(char type)
{
	this->type = type;
}

I_Instruction::~I_Instruction() {}

I_Instruction::I_Instruction(I_Instruction const& rhs)
{
	static_cast<void>(rhs);
	return ;
}

I_Instruction&			I_Instruction::operator=(I_Instruction const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

char					I_Instruction::getType()
{
	return this->type;
}

void					I_Instruction::set_index(int index)
{
	this->index = index;
}

int						I_Instruction::get_index(void)
{
	return this->index;
}

void					I_Instruction::set_partner_index(int index)
{
	this->partner_index = index;
}

int						I_Instruction::get_partner_index(void)
{
	return this->partner_index;
}