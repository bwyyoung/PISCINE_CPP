/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_zero_next.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_ZERO_NEXT_HPP
#define CMD_ZERO_NEXT_HPP

#include "I_Instruction.hpp"

class		cmd_zero_next : public I_Instruction
{
public:
	~cmd_zero_next();
	void					execute(int &cell_index, int &cell, int &instruction_index);
	char					getType();
	cmd_zero_next();
	cmd_zero_next(cmd_zero_next const & src);
	cmd_zero_next &			operator=(cmd_zero_next const & src);
};



#endif
