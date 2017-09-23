/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   I_Instruction.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PISCINE_C_I_INSTRUCTION_HPP
#define PISCINE_C_I_INSTRUCTION_HPP
#include <iostream>
#include <stdlib.h>
#include <list>
#include <fstream>
#include <ostream>
#include <string>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
#define UNUSED(x) static_cast<void>(x)
#define CMD_INCREMENT			'+'
#define CMD_DECREMENT			'-'
#define CMD_MVFORWARD			'>'
#define CMD_MVBACKWRD			'<'
#define CMD_PRINTCELL			'.'
#define CMD_WRITECELL			','
#define CMD_ZERO_SKIP			'['
#define CMD_ZERO_NEXT			']'
#define DEBUG_INPUT_CHAR		'T'
#define DEBUG_COUT_CELL_PRINT	1
#define DEBUG_CIN_CELL_WRITE	1

#define IMP_ASCII "ASCII"
#define IMP_32BIT "32BIT"
#define IMP_16BIT "16BIT"
#define IMP_8_BIT "8_BIT"

#define DEFAULT_IMPLEMENTATION IMP_ASCII

#define BIT_8_UNSIGNED					255
#define BIT_16_UNSIGNED					65535
#define BIT_32_UNSIGNED					4294967295

class		I_Instruction
{
protected:
	char				type;
	int					index;
	int					partner_index;
public:
	I_Instruction(char type);
	virtual 			~I_Instruction();
	virtual void		execute(int &cell_index, int &cell, int &instruction_index) = 0;
	char				getType();
	I_Instruction(I_Instruction const & src);
	I_Instruction&			operator=(I_Instruction const & src);
	void				set_index(int index);
	int					get_index(void);
	void				set_partner_index(int index);
	int					get_partner_index(void);
};

#endif
