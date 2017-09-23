/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_zero_skip.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_ZERO_SKIP_HPP
#define CMD_ZERO_SKIP_HPP

#include "I_Instruction.hpp"

class		cmd_zero_skip : public I_Instruction
{
public:
	~cmd_zero_skip();
	void					execute(int &cell_index, int &cell, int &instruction_index);
	char					getType();
	cmd_zero_skip();
	cmd_zero_skip(cmd_zero_skip const & src);
	cmd_zero_skip &			operator=(cmd_zero_skip const & src);
};

#endif
