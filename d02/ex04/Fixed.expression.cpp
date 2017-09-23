/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.expression.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

char Fixed::peek()
{
	return *expressionToParse;
}

char Fixed::get()
{
	return *expressionToParse++;
}

Fixed Fixed::get_fixed_number()
{
	double			num1 = std::strtod(expressionToParse, NULL);
	float			num = std::strtof(expressionToParse, NULL);
	int				count = 0;
	bool			found_dot = false;
	Fixed			result(num1);
	if (DEBUG)
	{///0.10001544f
		Fixed			result2(0.1f);
		Fixed			c(0.0078125f);
		if (SET_PRECISION)
			std::cout.precision(PRECISION);
		std::cout<< "strtod: " << num1 << std::endl;
		std::cout<< "strtof: " << num << std::endl;
		std::cout << "get_fixed_number " << result << std::endl;
		std::cout << "get_fixed_number2 " << result2 << std::endl;
		std::cout << "get_fixed_number3 " << c << std::endl;
		std::cout << (0.1f + 0.3f) << std::endl;
	}
	while ((peek() >= '0' && peek() <= '9') || (peek() == '.'))
	{
		if ((peek() == '.') && !found_dot)
			found_dot = true;
		else if ((peek() == '.') && found_dot)
			return (0); //error;
		count++;
		get();
	}

	return result;
}

Fixed	Fixed::factor()
{
	if (peek() >= '0' && peek() <= '9')
		return get_fixed_number();
	else if (peek() == '(')
	{
		get(); // '('
		Fixed result = evaluate();
		get(); // ')'
		return result;
	}
	else if (peek() == '-')
	{
		get();
		return -(factor());
	}
	return 0; // error
}

Fixed	Fixed::term()
{
	Fixed result = factor();
	while (peek() == '*' || peek() == '/')
		if (get() == '*')
			result *= factor();
		else
			result /= factor();
	return result;
}

Fixed	 Fixed::evaluate()
{
	Fixed	result = term();
	while (peek() == '+' || peek() == '-')
		if (get() == '+')
			result += term();
		else
			result -= term();
	return result;
}
