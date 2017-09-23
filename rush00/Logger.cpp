/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by jleblanc          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string const & filename)
{
	this->_filename = filename;
	this->_isOpen = false;
}

Logger::Logger(Logger const &o)
{
	this->_filename = o._filename+"~";
	this->_isOpen = false;
}

Logger &Logger::operator=(Logger const &)
{
	return (*this);
}

Logger::~Logger()
{
	if(this->_isOpen)
		this->_fs.close();
}


void Logger::log(std::string const & msg)
{
	if (!_isOpen)
	{
		this->_fs.open (this->_filename, std::fstream::in
								   | std::fstream::out | std::fstream::app);
		this->_isOpen = true;
	}

	std::string now;

	time_t      theTime = time(NULL);
	struct tm   *aTime = localtime(&theTime);
	char        s[32];
	strftime(s, sizeof(s), "[%Y%d%m_%H%M%S] ", aTime);
	now = std::string(s);

	this->_fs << now << ":" << msg << std::endl;
}