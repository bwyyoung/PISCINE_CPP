/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_convert.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "static_convert.hpp"

static_convert* static_convert::getInstance()
{
	static static_convert		instance;
	return (&instance);
}

static_convert::static_convert() {}

static_convert::~static_convert() {}

static_convert::static_convert(static_convert const& rhs)
{
	static_cast<void>(rhs);
	return ;
}

static_convert&			static_convert::operator=(static_convert const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

bool 					static_convert::check_double(std::string str)
{
	try
	{
		char*		endptr = 0;
		double x = std::strtod(str.c_str(), &endptr);
		if (endptr != 0)
			return false;
		if (errno == ERANGE || errno == EINVAL || x == MAX_DOUBLE
			|| x == MIN_DOUBLE || x == INF_DOUBLE)
		{
			errno = 0;
			return false;
		}
	}
	catch(std::invalid_argument& e)
	{
		return false;
	}
	catch(std::out_of_range& e)
	{
		return false;
	}
	catch(...)
	{
		return false;
	}
	return true;
}

bool					static_convert::check_float(std::string str)
{
	std::string::const_iterator	it = str.begin();
	bool						decimalPoint = false;
	size_t						minSize = 0;
	if(str.size()>0 && (str[0] == '-' || str[0] == '+'))
	{
		it++;
		minSize++;
	}
	while(it != str.end())
	{
		if(*it == '.')
		{
			if(!decimalPoint)
				decimalPoint = true;
			else
				break;
		}
		else if(!std::isdigit(*it) &&
				((*it!='f') || it + 1 != str.end() || !decimalPoint))
			break;
		++it;
	}
	try
	{
		char* endptr = 0;
		float x = std::strtof(str.c_str(), &endptr);
		if (errno == ERANGE || errno == EINVAL || x == MAX_FLOAT
			|| x == MIN_FLOAT || x == INF_FLOAT)
		{
			errno = 0;
			return false;
		}
	}
	catch(std::invalid_argument& e)
	{
		return false;
	}
	catch(std::out_of_range& e)
	{
		return false;
	}
	if ((str.size() > minSize && it == str.end()))
		return true;
	return  false;
}

bool					static_convert::check_char(std::string std_str)
{
	if (std_str.length() == 1)
		if (!std::isdigit(std_str[0]))
			if (std::isprint(std_str[0]))
				return true;
	return false;
}

bool 					static_convert::check_int(std::string std_str)
{
	int							x;
	std::string::const_iterator	it = std_str.begin();
	size_t						minSize = 0;

	if(std_str.size() > 0 && (std_str[0] == '-' || std_str[0] == '+'))
	{
		it++;
		minSize++;
	}
	while (it != std_str.end() && std::isdigit(*it))
		++it;
	try
	{
		x = std::stoi(std_str);
	}
	catch(std::invalid_argument& e)
	{
		return false;
	}
	catch(std::out_of_range& e)
	{
		return false;
	}
	catch(...)
	{
		return false;
	}
	long						test1 = std::strtol(std_str.c_str(), NULL, 0);
	long long					test2 = std::strtoll(std_str.c_str(), NULL, 0);
	static_cast<void>(test1);
	static_cast<void>(test2);
	if (errno == ERANGE)
	{
		errno = 0;
		return false;
	}
	bool flow = (std::atol(std_str.c_str()) <= INT_MAX && std::atol( std_str.c_str() ) >= INT_MIN);
	if (!flow)
		return false;
	return (std_str.size() > minSize && it == std_str.end());
}


void					static_convert::convert_test(char *str)
{
	std::string		test_string(str);

	if (this->check_pseudo_literals(test_string))
		return;
	if (this->check_char(test_string))
		this->convert_char(test_string);
	else if (this->check_int(test_string))
		this->convert_int(test_string);
	else if (this->check_float(test_string))
		this->convert_float(test_string);
	else if (this->check_double(test_string))
		this->convert_double(test_string);
	else
	{
		if (DEBUG)
			std::cout << "PRINT_FAIL" << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

bool					static_convert::check_pseudo_literals(std::string str)
{
	bool		is_pseudo = false;
	if (str == STR_NAN || str == STR_NANF ||
		str == STR_INFF_P || str == STR_INF_P ||
		str == STR_INFF_N || str == STR_INF_N)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		is_pseudo = true;
	}
	if ( str == STR_NAN || str == STR_NANF )
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == STR_INFF_P || str == STR_INF_P)
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == STR_INFF_N || str == STR_INF_N)
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	return is_pseudo;
}


void					static_convert::convert_char(const std::string str)
{
	if (DEBUG)
		std::cout << "PRINT_CHAR" << std::endl;
	std::cout << "char: '" << str[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f" <<  std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

void					static_convert::convert_int(const std::string str)
{
	if (DEBUG)
		std::cout << "PRINT_INT" << std::endl;
	int			i = std::atoi(str.c_str());
	if (std::isprint(i))
		std::cout << "char: '" << static_cast<char> (i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if ( std::fmod (static_cast<double>(i), 1) == 0)
	{
		std::cout << std::setprecision( std::strlen(str.c_str())) << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << std::setprecision( std::strlen(str.c_str())) << "double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	else
	{

		std::cout << std::setprecision(std::strlen(str.c_str())) << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << std::setprecision(std::strlen(str.c_str())) << "double: " << static_cast<double>(i) << std::endl;
	}
}

void					static_convert::convert_float(const std::string str)
{
	if (DEBUG)
		std::cout << "PRINT_FLOAT" << std::endl;
	float		i = std::strtof(str.c_str(), NULL);
	if (std::isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if ( i <= INT_MAX  && i >= INT_MIN && check_int(str))
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (std::fmod(i, 1) == 0)
	{
		std::cout << std::setprecision(std::strlen(str.c_str()))
				<< "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << std::setprecision(std::strlen(str.c_str()))
				<< "double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	else
	{
		std::cout << std::setprecision(std::strlen(str.c_str()))
				<< "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << std::setprecision(std::strlen(str.c_str()))
				<< "double: " << static_cast<double>(i) << std::endl;
	}
}

void					static_convert::convert_double(const std::string str)
{
	if (DEBUG)
		std::cout << "PRINT_DOUBLE" << std::endl;
	double		i = std::strtod(str.c_str(), NULL);
	if (std::isprint(i))
		std::cout << "char: '" << static_cast<char>(i)<< "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if ( i <= INT_MAX  && i >= INT_MIN && check_int(str))
		std::cout << "int: " << static_cast<int>(i)<< std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (i <= MAX_FLOAT && i >= MIN_FLOAT && check_float(str))
	{
		if (std::fmod(i,1) == 0)
			std::cout<<std::setprecision(std::strlen(str.c_str()))<<"float: " << static_cast<float>(i) << ".0f" << std::endl;
		else
			std::cout<<std::setprecision(std::strlen(str.c_str())) <<  "float: " << static_cast<float>(i) << "f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
	if (std::fmod(i,1) == 0)
		std::cout << std::setprecision(std::strlen(str.c_str())) <<  "double: " <<i<< ".0" <<std::endl;
	else
		std::cout << std::setprecision(std::strlen(str.c_str())) <<  "double: " <<i<< std::endl;
}