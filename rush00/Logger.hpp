/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by jleblanc          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>

class Logger
{
private:
	std::string	_filename;
	std::fstream 		_fs;
	bool 			_isOpen;

public:
	//Coplein
	Logger(void);
	Logger(std::string const & filename);
	Logger(Logger const &src);
	Logger	&operator=(Logger const &src);
	~Logger(void);

	void log(std::string const & msg);
};

#endif
