/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED__
# define __FIXED__

#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iomanip>

#define DEBUG 0
#define BIT_FRACTION 8
#define BITS_FRAC_DEC 256.0f
#define PRECISION 20
#define SET_PRECISION false

class		Fixed
{
public:
	Fixed(void);
	Fixed(std::string expression);
	Fixed(const int &num);
	Fixed(const float &num);
	Fixed(const double &num);
	Fixed(char *expression);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed&				operator=(Fixed const &rhs);
	Fixed				operator+(Fixed const &rhs);
	Fixed				operator-(Fixed const &rhs);
	Fixed				operator*(Fixed const &rhs);
	Fixed				operator/(Fixed const &rhs);

	bool				operator>(Fixed const &rhs)const;
	bool				operator<(Fixed const &rhs)const;
	bool				operator>=(Fixed const &rhs)const;
	bool				operator<=(Fixed const &rhs)const;
	bool				operator==(Fixed const &rhs)const;
	bool				operator!=(Fixed const &rhs)const;

	//negate operator
	Fixed&				operator-();
	Fixed&				operator+=(Fixed const &rhs);
	Fixed&				operator-=(Fixed const &rhs);
	Fixed&				operator*=(Fixed const &rhs);
	Fixed&				operator/=(Fixed const &rhs);

	//http://en.cppreference.com/w/cpp/language/operator_incdec
	//prefix
	Fixed&				operator++();
	//postfix
	Fixed				operator++(int);
	//prefix
	Fixed&				operator--();
	//postfix
	Fixed				operator--(int);

	static Fixed		max(Fixed const & a, Fixed const & b);
	static Fixed		min(Fixed const & a, Fixed const & b);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	int					toInt(void) const;
	float				toFloat(void) const;
	double				toDouble(void) const;

	//Recursive Event Parser For ex04
	Fixed				term();
	Fixed				factor();
	Fixed				evaluate();
	Fixed				get_fixed_number();
	char				peek();
	char				get();
private:
	char				*expressionToParse;
	int					number;
	static const int	bits_fractional = BIT_FRACTION;
};

std::ostream& operator<<(std::ostream &o, Fixed const & rhs);

#endif