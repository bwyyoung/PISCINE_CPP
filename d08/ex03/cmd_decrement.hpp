/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_decrement.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_DECREMENT_HPP
#define CMD_DECREMENT_HPP

#include "I_Instruction.hpp"

class		cmd_decrement : public I_Instruction
{
public:
	~cmd_decrement();
	void					execute(int &cell_index, int &cell, int &instruction_index);
	char					getType();
	cmd_decrement();
	cmd_decrement(cmd_decrement const & src);
	cmd_decrement &			operator=(cmd_decrement const & src);
};

#endif
