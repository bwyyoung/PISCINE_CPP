/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mvbackwrd.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_MVBACKWRD_HPP
#define CMD_MVBACKWRD_HPP

#include "I_Instruction.hpp"

class		cmd_mvbackwrd : public I_Instruction
{
public:
	~cmd_mvbackwrd();
	void					execute(int &cell_index, int &cell, int &instruction_index);
	char					getType();
	cmd_mvbackwrd();
	cmd_mvbackwrd(cmd_mvbackwrd const & src);
	cmd_mvbackwrd &			operator=(cmd_mvbackwrd const & src);
};


#endif
