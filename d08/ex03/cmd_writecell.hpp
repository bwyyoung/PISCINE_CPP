/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_writecell.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_WRITECELL_HPP
#define CMD_WRITECELL_HPP

#include "I_Instruction.hpp"

class		cmd_writecell : public I_Instruction
{
public:
	~cmd_writecell();
	void					execute(int &cell_index, int &cell, int &instruction_index);
	char					getType();
	cmd_writecell();
	cmd_writecell(cmd_writecell const & src);
	cmd_writecell &			operator=(cmd_writecell const & src);
};



#endif
