/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

replace::replace(char **argv)
{
	this->FILENAME = argv[1];
	this->s1 = argv[2];
	this->s2 = argv[3];
}

replace::~replace()
{

}

void	replace::start()
{
	std::ifstream	in(this->FILENAME);
	std::ofstream	out(this->FILENAME + ".replace");
	std::string		wordToReplace(this->s1);
	std::string		wordToReplaceWith(this->s2);
	size_t			len = wordToReplace.length();
	size_t			len2 = wordToReplaceWith.length();
	std::string		line;
	size_t			current_pos;
	bool			firstwhile = true;
	size_t			numlines = 0;

	if (!len || !len2)
	{
		std::cout << "Invalid replacement strings" << std::endl;
		return ;
	}
	if (!in)
	{
		std::cout << "Could not open " << this->FILENAME << std::endl;
		return ;
	}
	if (!out)
	{
		std::cout << "Could not open "
				<< this->FILENAME + ".replace" << std::endl;
		return ;
	}
	while (std::getline(in, line))
	{
		if (!firstwhile)
			out << '\n';
		else
			firstwhile = false;
		current_pos = 0;
		while (true)
		{
			size_t pos = line.find(wordToReplace, current_pos);
			if (pos != std::string::npos)
			{
				line.replace(pos, len, wordToReplaceWith);
				current_pos = pos + len2;
			}
			else
				break;
		}
		out << line;
		numlines++;
	}
	if (!int(line[0]) && numlines > 0)
		out << '\n';
	out.close();
	in.close();
}