/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

phonebook::phonebook()
{
	this->cur_records_size = NUM_RECORDS;
	this->record_inc = 5;
}

phonebook::~phonebook()
{
	
}

void	phonebook::test_record_add()
{
	int		i = -1;
	int 	j;

	while (++i < 8)
	{
		j = -1;
		while (++j < NUM_PARAM)
		{
			this->m_records[i].i = 1;
			this->m_records[i].data[j] = std::to_string(i) + "->1234567890abcdefghijk";
		}
	}
}

void	phonebook::start_input(void)
{
	std::string		command;
	while (std::cin)
	{
		std::cout << "INPUT COMMAND (ADD, SEARCH, EXIT):" << std::endl;
		std::cin.clear();
		std::cin >> command;
		if (!command.compare(EXIT))
			break;
		else if (!command.compare(ADD))
			this->record_add();
		else if (!command.compare(SEARCH))
			this->record_search();
	}
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	phonebook		book;
	//book.test_record_add();
	book.start_input();
	return (0);
}
