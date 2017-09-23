/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_printcell.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_PRINTCELL_HPP
#define CMD_PRINTCELL_HPP

#include "I_Instruction.hpp"

class		cmd_printcell : public I_Instruction
{
public:
	~cmd_printcell();
	void					execute(int &cell_index, int &cell, int &instruction_index);
	char					getType();
	cmd_printcell();
	cmd_printcell(cmd_printcell const & src);
	cmd_printcell &			operator=(cmd_printcell const & src);
};



#endif
