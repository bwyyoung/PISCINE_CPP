/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mvforward.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_MVFORWARD_HPP
#define CMD_MVFORWARD_HPP

#include "I_Instruction.hpp"

class		cmd_mvforward : public I_Instruction
{
public:
	~cmd_mvforward();
	void					execute(int &cell_index, int &cell, int &instruction_index);
	char					getType();
	cmd_mvforward();
	cmd_mvforward(cmd_mvforward const & src);
	cmd_mvforward &			operator=(cmd_mvforward const & src);
};


#endif
