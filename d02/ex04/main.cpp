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

int		main(int argc, char **argv)
{

	if (argc != 2)
		return (0);
	Fixed	test(argv[1]);
	Fixed	result = test.evaluate();
	// ./eval_expr "( 18.18 + 3.03 ) * 2"
	// 42.4219
	if (SET_PRECISION)
		std::cout.precision(PRECISION);
	std::cout << result << std::endl;
	return 0;
}
