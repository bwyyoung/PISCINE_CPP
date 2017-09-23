/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int		main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "START BASIC TEST" << std::endl;
	Fixed c(0.0078125f);
	Fixed d(0.1f); //0.100000000000000
	std::cout.precision(20);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "-------CUSTOM TESTS-------" << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;
	std::cout << "D: " << d << std::endl;
	std::cout << "MIN: " << Fixed::min( a, b ) << std::endl;
	std::cout << "A + B: " << (a + b) << std::endl;
	std::cout << "A - B: " << (a - b) << std::endl;
	std::cout << "A / B: " << (a / b) << std::endl;
	std::cout << "B / A: " << (Fixed(b) / a) << std::endl;
	std::cout << "A * B: " << (a * b) << std::endl;

	std::cout << "A < B: " << (a < b) << std::endl;
	std::cout << "A > B: " << (a > b) << std::endl;
	std::cout << "A <= B: " << (a <= b) << std::endl;
	std::cout << "A >= B: " << (a >= b) << std::endl;
	std::cout << "A == B: " << (a == b) << std::endl;

	std::cout << "A < C: " << (a < c) << std::endl;
	std::cout << "A > C: " << (a > c) << std::endl;
	std::cout << "A <= C: " << (a <= c) << std::endl;
	std::cout << "A >= C: " << (a >= c) << std::endl;
	std::cout << "A == C: " << (a == c) << std::endl;
	return 0;
}

/* OUTPUT
$> clang++ -Wall -Wextra -Werror Fixed.class.cpp main.cpp
$> ./a.out 0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
*/