/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_convert.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PISCINE_C_STATIC_CONVERT_HPP
#define PISCINE_C_STATIC_CONVERT_HPP
#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>
#include <float.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <errno.h>

#define STR_INFF_P	"+inff"
#define STR_INFF_N	"-inff"
#define STR_INF_P	"+inf"
#define STR_INF_N	"-inf"
#define STR_NAN		"nan"
#define STR_NANF	"nanf"

#define MAX_DOUBLE std::numeric_limits<double>::max()
#define MIN_DOUBLE std::numeric_limits<double>::min()
#define INF_DOUBLE std::numeric_limits<double>::infinity()

#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_FLOAT std::numeric_limits<float>::min()
#define INF_FLOAT std::numeric_limits<float>::infinity()

#define DEBUG 0

class static_convert
{
public:
	static static_convert*	getInstance();
	void					convert_test(char *str);
	~static_convert(void);
private:
	static_convert(void);
	static_convert(static_convert const & src);
	static_convert &		operator=(static_convert const & src);
	bool					check_char(std::string str);
	bool					check_double(std::string str);
	bool					check_int(std::string str);
	bool					check_float(std::string str);
	bool					check_pseudo_literals(std::string str);
	void					convert_char(const std::string str);
	void					convert_int(const std::string str);
	void 					convert_double(const std::string str);
	void					convert_float(const std::string str);
};


#endif //PISCINE_C_STATIC_CONVERT_HPP
