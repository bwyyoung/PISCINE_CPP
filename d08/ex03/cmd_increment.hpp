/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_increment.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_INCREMENT_HPP
#define CMD_INCREMENT_HPP

#include "I_Instruction.hpp"

class		cmd_increment : public I_Instruction
{
public:
	~cmd_increment();
	void					execute(int &cell_index, int &cell, int &instruction_index);
	char					getType();
	cmd_increment();
	cmd_increment(cmd_increment const & src);
	cmd_increment &			operator=(cmd_increment const & src);
};



#endif
