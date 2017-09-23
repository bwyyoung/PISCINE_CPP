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
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int &num)
{
	std::cout << "Int constructor called" << std::endl;
	this->number = num << this->bits_fractional;
}

Fixed::Fixed(const float &num)
{
	std::cout << "Float constructor called" << std::endl;
	this->number = roundf(num * (1 << this->bits_fractional));
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

const char *byte_to_binary(int x)
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

float	Fixed::toFloat(void) const
{
	unsigned int	mask = (1 << this->bits_fractional) - 1;
	int				to_fraction = this->number & mask;

	float			final_num = (float)this->toInt() + (float)to_fraction / 256.0;
	return (final_num);
}

int		Fixed::toInt(void) const
{
	int		i = -1;
	int		int_number;

	int_number = this->number;
	while (++i < this->bits_fractional)
		int_number >>= 1;
	return (int_number);
}

std::ostream& operator<<(std::ostream &o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	if (this == &rhs)
		return *this;
	std::cout << "Assignation operator called" << std::endl;
	this->number = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void	Fixed::setRawBits(int const raw)
{
	this->number = raw;
	return;
}
