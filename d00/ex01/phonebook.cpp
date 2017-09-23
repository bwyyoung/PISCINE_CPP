/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

const std::string phonebook::record_strings[] = {
		"firstname", "lastname", "nickname", "login", "postal address",
		"email address", "phone number", "birthday date", "favorite meal",
		"underwear color", "darkest secret"};

int		phonebook::get_record_index(void)
{
	int		i = -1;

	while (++i < (int)this->cur_records_size)
	{
		if (!this->m_records[i].i)
			return ((int)i);
	}
	return (-1);
}

void 	phonebook::record_add(void)
{
	int				i = -1;
	std::string		record;
	int				cur_index = get_record_index();

	if (cur_index < 0)
	{
		std::cout << "PHONE RECORDS FULL"<< std::endl;
		return ;
	}
	this->m_records[cur_index].i = 1;
	while (++i < NUM_PARAM)
	{
		std::cout << record_strings[i];
		std::cout << ": ";
		std::cin >> record;
		this->m_records[cur_index].data[i] = record;
		if (std::cin.eof())
			exit(0);
	}
}

void	phonebook::print_record_basic(std::string therecord[], int index)
{
	int				i = -1;
	std::cout << std::setw (10) << index << "|";
	while (++i < 3)
		std::cout << std::setw (10) <<
		(therecord[i].length() > 10 ? therecord[i].substr(0,9) + '.'
									: therecord[i]) << "|";
	std::cout << std::endl;
}

void	phonebook::print_record_detailed(int index)
{
	int		i = -1;

	if (index < 0 || index >= (int)this->cur_records_size)
		return ;
	if (!this->m_records[index].i)
		return ;
	while (++i < NUM_PARAM)
		std::cout << this->record_strings[i] << ": "
				<< this->m_records[index].data[i] << std::endl;
}


inline bool isInteger(const std::string & s)
{
	if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
		return false ;
	char * p ;
	std::strtol(s.c_str(), &p, 10) ;
	return (*p == 0) ;
}

void 	phonebook::record_search(void)
{
	int				i = -1;
	std::string		command;
	bool			has_one_record = false;

	while (++i < (int)this->cur_records_size)
	{
		if (!this->m_records[i].i)
			break;
		print_record_basic(this->m_records[i].data, i);
		has_one_record = true;
	}
	if (!has_one_record)
	{
		std::cout << "NO PHONE RECORDS"<< std::endl;
		return ;
	}
	while (std::cin)
	{
		std::cout << "INPUT INDEX (EXIT to quit):" << std::endl;
		std::cin >> command;
		if (std::cin.eof())
			exit(0);
		if (!command.compare(EXIT))
			break;
		if (isInteger(command))
			print_record_detailed(std::stoi(command));
	}
}
