/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mindopen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mindopen.hpp"

Mindopen::Mindopen()
{
	this->clear_all_data();
}

Mindopen::~Mindopen()
{
	this->clear_all_data();
}

void				Mindopen::clear_all_data()
{
	int i = -1;
	while (!this->input_list.empty())
		this->input_list.pop_back();
	while (!this->instruction_list.empty())
	{
		delete this->instruction_list.back();
		this->instruction_list.pop_back();
	}
	this->error_description = "";
	this->FILENAME_INPUT = "";
	this->FILENAME_OUTPUT = "";
	this->FILENAME_PROGRAM = "";
	this->current_cell_index = 0;
	this->current_instruction_index = 0;
	while (++i < CELL_LIMIT)
		this->CELL_CONTAINER[i] = 0;
	this->file_input_enable = false;
	if (DEFAULT_IMPLEMENTATION == IMP_ASCII)
	{
		this->cell_lower_range = 0;
		this->cell_upper_range = BIT_8_UNSIGNED;
	}
	else if (DEFAULT_IMPLEMENTATION == IMP_8_BIT)
	{
		this->cell_lower_range = -128;
		this->cell_upper_range = 127;
	}
	else if (DEFAULT_IMPLEMENTATION == IMP_16BIT)
	{
		this->cell_lower_range = -32768;
		this->cell_upper_range = 32767;
	}
	else if (DEFAULT_IMPLEMENTATION == IMP_32BIT)
	{
		this->cell_lower_range = -2147483648;
		this->cell_upper_range = 2147483647;
	}
}

int					Mindopen::get_cell_lower_range(void)
{
	return this->cell_lower_range;
}

int					Mindopen::get_cell_upper_range(void)
{
	return this->cell_upper_range;
}

Mindopen::Mindopen(Mindopen const& rhs)
{
	static_cast<void>(rhs);
	return ;
}

Mindopen&			Mindopen::operator=(Mindopen const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

Mindopen*			Mindopen::getInstance()
{
	static Mindopen		instance;
	// Guaranteed to be destroyed.
	// Instantiated on first use.
	return &instance;
}

bool				Mindopen::read_sub_loop(cmd_zero_skip *anchor,
										std::ifstream &stream,
										std::string &line,
										std::string::size_type &index)
{
	//if Anchor is null, we are NOT in a sub loop, and are instead in the main loop
	//otherwise we need to read the current line;
	if (anchor != NULL)
	{
		//we are in a sub loop, and need to check current line.
		if (index >= line.size()) //already reached end of current line
		{
			index = 0;
			if (!std::getline(stream, line)) //read the next line
			{//EOF
				this->error_description = "Trapped within Loop with no end!";
				throw MindopenException(*this);
			}
			//start reading a new line in search of the end of this loop, from position 0
			return (this->read_line(anchor, stream, line, index));
			//index = new_index;
		}
		else
			//otherwise, we continue reading the current line at last index,
			// as there are instructions to be read.
			return  (this->read_line(anchor, stream, line, index));
			//found the end bracket, we can quit now.
	}//anchor is null, we try to get another line
	else if (!std::getline(stream, line)) //END OF FILE, quit
		return false;
	index = 0;
	//not in sub loop, in ROOT level. read the newly obtained line.
	return (this->read_line(NULL, stream, line, index));
}

bool				Mindopen::read_line(cmd_zero_skip *anchor,
									std::ifstream &stream,
									std::string &line,
									std::string::size_type &index)
{
	//we first read the line printed inside the file..
	//the line could contain the START bracket, in which case
	//we break into reading a sub loop.
	//if we are currently reading a line, and find the END bracket,
	//that means we need to tell it the START brackets address,
	//and that the START needs to know the END BRACKET ADDRESS
	I_Instruction					*current_instruction;
	cmd_zero_skip					*current_zero_skip = NULL; // '['
	cmd_zero_next					*current_zero_next = NULL; // ']'
	std::string::size_type			i;
	for (i = index; i < line.size(); i++)
	{
		current_instruction = NULL;
		current_zero_skip = NULL;
		current_zero_next = NULL;
		if (DEBUG)
			std::cout << line[i];
		switch (line[i])
		{
			case CMD_INCREMENT:
				current_instruction = new cmd_increment();
				break;
			case CMD_DECREMENT:
				current_instruction = new cmd_decrement();
				break;
			case CMD_MVFORWARD:
				current_instruction = new cmd_mvforward();
				break;
			case CMD_MVBACKWRD:
				current_instruction = new cmd_mvbackwrd();
				break;
			case CMD_PRINTCELL:
				current_instruction = new cmd_printcell();
				break;
			case CMD_WRITECELL:
				current_instruction = new cmd_writecell();
				break;
			case CMD_ZERO_SKIP:
				current_zero_skip = new cmd_zero_skip();
				current_instruction = current_zero_skip;
				break;
			case CMD_ZERO_NEXT:
				current_zero_next = new cmd_zero_next();
				current_instruction = current_zero_next;
				break;
			case FILE_COMMENT:
				//end_read_line = true;
				//some files do have # comments within
				//BF code. so we need to leave this out for now..
				break;
			case FILE_CHAR_SPACE:
			case FILE_CHAR_TAB:
				break;
			default:
				//ignore all other characters
				break;
		}
		if (!current_instruction)
			continue;
		current_instruction->set_index(this->current_instruction_index);
		this->instruction_list.push_back(current_instruction);
		this->current_instruction_index++;
		if (current_zero_skip) // we got a starter bracket, so we need to break into a sub loop
		{
			if (DEBUG2)
				std::cout << std::endl << "!Start Loop("<< std::to_string(i) <<")!"
						  <<"[" << std::to_string(current_zero_skip->get_index())<< std::endl;
			i++; //move on to next character for the sub level to pick up on.
			this->read_sub_loop(current_zero_skip, stream, line, i);
			if (DEBUG2)
				std::cout << "!Exited Sub Loop("<< std::to_string(i) <<")!~~}"
						  << line << std::endl;
			//we have traveled to a sub loop that could be on the same line, or newline.
			//continue looping this current line, which may be another line
			//in another part of the file.
			//index i was updated under the sub loop.
		}
		else if (current_zero_next)
		{
			if (DEBUG2)
				std::cout << std::endl << "!End Loop("<< std::to_string(i) <<")!  ["
				<< std::to_string(anchor->get_index())
				<<", "<< std::to_string(current_zero_next->get_index()) <<"]"<< std::endl;
			// this is the end of the loop. notify starter bracket of its position.
			this->instruction_list[this->current_instruction_index - 1]
					->set_partner_index(anchor->get_index());
			this->instruction_list[anchor->get_index()]
					->set_partner_index(current_zero_next->get_index());
			index = i; //allow parent level to get to next position.
			return true; //YES, we have found the end of this loop.
		}
		//more lines to be read until i == line_size;
	}
	index = i;
	if (DEBUG)
		std::cout << std::endl;
	if (anchor != NULL)//NO, we have not yet found the end of the loop
		//we are currently searching for the end bracket. so we need to call
		//sub loop again to read next line
		return (this->read_sub_loop(anchor, stream, line, index));
	index = 0;
	//otherwise go back to sub loop to continue reading file, as ROOT level
	//with NULL/NO anchor '['
	return (this->read_sub_loop(NULL, stream, line, index));
}

void				Mindopen::open_program_file(char *filename)
{
	this->clear_all_data();
	std::string				file(filename);
	this->FILENAME_PROGRAM = file;
	this->FILENAME_OUTPUT = file + ".mindopen.output";
	std::string					line;
	std::string::size_type		start_index = 0;
	std::ifstream				in(this->FILENAME_PROGRAM);
	if (!in)
	{
		std::cout << "Could not open " << this->FILENAME_PROGRAM << std::endl;
		std::exit(0);
	}
	try
	{
		this->read_sub_loop(NULL, in, line, start_index);
	}
	catch (MindopenException e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	in.close();
}

void				Mindopen::open_input_file(char	*filename)
{
	this->file_input_enable = true;
	std::string				file(filename);
	this->FILENAME_INPUT	= file;
	std::ifstream			in(this->FILENAME_INPUT);
	std::string				line;
	if (!in)
	{
		std::cout << "Could not open " << this->FILENAME_INPUT << std::endl;
		std::exit(0);
	}
	if (DEBUG)
		std::cout << "opening input file: " << file << std::endl;

	while (std::getline(in, line))
	{
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
		for (std::string::size_type i = 0; i < line.size(); ++i)
		{
			if (DEBUG2)
				std::cout<< line[i];
			this->input_list.push_back(line[i]);
		}
		if (DEBUG2)
			std::cout << std::endl;
	}
	in.close();
}

int				Mindopen::get_input(void)
{
	int		size = static_cast<int>(this->input_list.size());
	if (this->current_input_index >= size || !file_input_enable)
	{
		this->error_description = "Input Index larger than container!";
		if (!file_input_enable)
			this->error_description = "No File Input Specified!";
		throw MindopenException(*this);
	}
	int			the_input = static_cast<int>(this->input_list[this->current_input_index]);
	this->current_input_index++;
	return the_input;
}

bool			Mindopen::file_input_enabled()
{
	return this->file_input_enable;
}

void				Mindopen::execute_program()
{
	int		instruction_size = static_cast<int>(this->instruction_list.size());
	this->current_cell_index = 0;
	this->current_instruction_index = -1;
	int		current_cell_value;
	int		old_cell_index;
	while (++this->current_instruction_index < instruction_size)
	{
		if (DEBUG3)
			std::cout << std::to_string(this->current_cell_index) << "|"
		 << this->instruction_list[this->current_instruction_index]->getType() << "|"
							 << std::to_string(this->current_instruction_index) << std::endl;
		current_cell_value = this->CELL_CONTAINER[this->current_cell_index];
		old_cell_index = this->current_cell_index;
		this->instruction_list[this->current_instruction_index]
				->execute(
						this->current_cell_index,
						current_cell_value,
						this->current_instruction_index);
		this->CELL_CONTAINER[old_cell_index] = current_cell_value;
		if (DEBUG3)
			std::cout <<"~"<< std::to_string(this->current_cell_index) << "|"
					  << this->instruction_list[this->current_instruction_index]->getType() << "|"
					  << std::to_string(this->CELL_CONTAINER[old_cell_index]) <<"|"
					  << this->current_instruction_index << "~"<< std::endl;
	}
}

Mindopen::MindopenException::~MindopenException(void) throw() {}
Mindopen::MindopenException::MindopenException(Mindopen &f)
{
	parent = &f;
}

const char *			Mindopen::MindopenException::what() const throw()
{
	std::string error = "Input File Invalid/Corrupted. Mindopen could not process the information.";
	if (this->parent != NULL)
		return this->parent->error_description.c_str();
	return error.c_str();
}

Mindopen::MindopenException::MindopenException(MindopenException const & src) : parent(NULL)
{
	*this = src;
}

Mindopen::MindopenException & Mindopen::MindopenException::operator=(MindopenException const & rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
