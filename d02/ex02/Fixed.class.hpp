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

#define DEBUG 0

class Fixed
{
public:
	Fixed(void);
	Fixed(const int &num);
	Fixed(const float &num);
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
	float				toFloat( void ) const;
private:
	int					number;
	static const int	bits_fractional = 8;
};

std::ostream& operator<<(std::ostream &o, Fixed const & rhs);

#endif