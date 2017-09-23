/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LOGGER__
#define __LOGGER__

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

#define CONSOLE "CONSOLE"
#define FILE "FILE"

class Logger
{
private:
	void		logToConsole(std::string log);
	void		logToFile(std::string log);
	std::string	makeLogEntry(std::string log);
	std::string	logfile;
public:
	Logger();
	~Logger();
	void		log(std::string const &dest, std::string const &message);
};

#endif