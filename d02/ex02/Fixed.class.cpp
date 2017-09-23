/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void)
{
	this->number = 0;
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int &num)
{
	if (DEBUG)
		std::cout << "Int constructor called" << std::endl;
	this->number = num << this->bits_fractional;
}

Fixed::Fixed(const float &num)
{
	if (DEBUG)
		std::cout << "Float constructor called" << std::endl;
	this->number = (int)roundf(num * (1 << this->bits_fractional));
}

Fixed::Fixed(Fixed const & src)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	return;
}

const char			*byte_to_binary(int x)
{
	static char b[9];
	b[0] = '\0';

	int z;
	for (z = 128; z > 0; z >>= 1)
	{
		strcat(b, ((x & z) == z) ? "1" : "0");
	}

	return b;
}

float				Fixed::toFloat(void) const
{
	unsigned int	mask = (1 << this->bits_fractional) - 1;
	int				to_fraction = this->number & mask;

	//256 is 11111111 in binary (8 bits of 1)
	float			final_num = (float)this->toInt()
							+ (float)to_fraction / 256.0f;
	return (final_num);
}

int					Fixed::toInt(void) const
{
	int		i = -1;
	int		int_number;

	int_number = this->number;
	while (++i < this->bits_fractional)
		int_number >>= 1;
	return (int_number);
}

std::ostream&		operator<<(std::ostream &o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

int					Fixed::getRawBits(void) const
{
	if (DEBUG)
		std::cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void				Fixed::setRawBits(int const raw)
{
	this->number = raw;
	return;
}

Fixed&				Fixed::operator=(Fixed const & rhs)
{
	if (this == &rhs)
		return *this;
	if (DEBUG)
		std::cout << "Assignation operator called" << std::endl;
	this->number = rhs.getRawBits();
	return *this;
}

Fixed				Fixed::operator+(Fixed const &rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}
Fixed				Fixed::operator-(Fixed const &rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed				Fixed::operator*(Fixed const &rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}
Fixed				Fixed::operator/(Fixed const &rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

bool				Fixed::operator>(Fixed const &rhs)const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool				Fixed::operator<(Fixed const &rhs)const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool				Fixed::operator>=(Fixed const &rhs)const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool				Fixed::operator<=(Fixed const &rhs)const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool				Fixed::operator==(Fixed const &rhs)const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool				Fixed::operator!=(Fixed const &rhs)const
{
	return (this->getRawBits() != rhs.getRawBits());
}

//prefix
Fixed&				Fixed::operator++()
{
	this->number += 1;
	return (*this);
}

//postfix
Fixed				Fixed::operator++(int)
{
	Fixed copy(*this);
	++(*this);
	return copy;
}

//prefix
Fixed&				Fixed::operator--()
{
	this->number -= 1;
	return (*this);
}

//postfix
Fixed				Fixed::operator--(int)
{
	Fixed copy(*this);
	--(*this);
	return copy;
}

Fixed				Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed				Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}