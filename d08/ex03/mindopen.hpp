/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mindopen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINDOPEN_
#define _MINDOPEN_

#include "cmd_decrement.hpp"
#include "cmd_increment.hpp"
#include "cmd_mvbackwrd.hpp"
#include "cmd_mvforward.hpp"
#include "cmd_printcell.hpp"
#include "cmd_writecell.hpp"
#include "cmd_zero_next.hpp"
#include "cmd_zero_skip.hpp"
#include <algorithm>

#define DEBUG				0
#define DEBUG2				0
#define DEBUG3				0
#define CELL_LIMIT			30000
#define FILE_CHAR_SPACE		' '
#define FILE_CHAR_TAB		'\t'
#define FILE_COMMENT		'#'
//TODO: research on GETCHAR to get user input for brainfuck (,) inputs
//TODO: Also, work on writing to external file if input file is specified.
class		Mindopen
{
private:
	Mindopen(void);
	Mindopen(Mindopen const & src);
	Mindopen &					operator=(Mindopen const & src);
	std::string					FILENAME_PROGRAM;
	std::string					FILENAME_INPUT;
	std::string					FILENAME_OUTPUT;
	std::string					error_description;
	int							current_cell_index;
	int							current_input_index;
	int							current_instruction_index;
	int							CELL_CONTAINER[CELL_LIMIT];
	std::vector<I_Instruction*>	instruction_list;
	std::vector<char>			input_list;
	void						clear_all_data();
	bool						read_sub_loop(cmd_zero_skip *anchor,
											std::ifstream &stream,
											std::string &line,
											std::string::size_type &index);
	bool						read_line(cmd_zero_skip *anchor,
											std::ifstream &stream,
											std::string &line,
											std::string::size_type &index);
	bool						file_input_enable;
	int							cell_lower_range;
	int							cell_upper_range;
public:
	~Mindopen(void);
	int					get_input(void);
	static Mindopen*	getInstance();
	void				open_program_file(char	*filename);
	void				open_input_file(char	*filename);
	void				execute_program();
	bool				file_input_enabled();

	int					get_cell_lower_range(void);
	int					get_cell_upper_range(void);
	class MindopenException : public std::exception
	{
	private:
		Mindopen *parent;
	public:
		MindopenException(Mindopen &f);
		MindopenException(MindopenException const & src);
		virtual ~MindopenException(void) throw();
		MindopenException & operator=(MindopenException const & rhs);
		virtual const char * what() const throw();
	};
};

#endif