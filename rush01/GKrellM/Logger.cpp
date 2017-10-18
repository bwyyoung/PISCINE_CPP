/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger()
{
	logfile = "Logger.txt";
}

Logger::~Logger()
{

}

void		Logger::logToConsole(std::string log_str)
{
	std::cout << log_str << std::endl;
}

void		Logger::logToFile(std::string log_str)
{
	std::ofstream	new_file(logfile, std::ofstream::app);
	if (!new_file)
	{
		std::cout << "Output File Error" << std::endl;
		return;
	}
	new_file << log_str << std::endl;
	new_file.close();
}

std::string	Logger::makeLogEntry(std::string log_str)
{
	std::stringstream	buffer;
	std::time_t			t = std::time(0);
	struct tm 			*now = std::localtime( & t );
	buffer << '[' << (now->tm_year + 1900)
		   << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
		   << std::setw(2) << std::setfill('0') << now->tm_mday
		   << '_'
		   << std::setw(2) << std::setfill('0') << now->tm_hour
		   << std::setw(2) << std::setfill('0') << now->tm_min
		   << std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
	return (buffer.str() + log_str);
}

void		Logger::log(std::string const &dest, std::string const &message)
{
	int		i = -1;
	std::string	new_log = this->makeLogEntry(message);
	void (Logger::*array_pointer[2])(std::string target) =
			{
					&Logger::logToConsole,
					&Logger::logToFile
			};
	const std::string attack_key[2] =
			{
					CONSOLE,
					FILE
			};
	while (++i < 2)
		if (attack_key[i] == dest)
			(this->*array_pointer[i])(new_log);
}