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

#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Victim.hpp"

#define MORE_TEST 1

int		main(void) 
{
	if (MORE_TEST)
	std::cout<< "----------STANDARD_TEST-----------" << std::endl;
	{
		Sorcerer	robert("Robert", "the Magnificent");
		Victim		jim("Jimmy");
		Peon		joe("Joe");

		std::cout << robert << jim << joe;
		robert.polymorph(jim);
		robert.polymorph(joe);
	}

	if (!MORE_TEST)
		return (0);
	std::cout<< "----------ADDITIONAL_TEST-----------" << std::endl;
	{
		Sorcerer robert("Robert", "the Magnificent");
		Victim *jack = new Peon("Joe");
		robert.polymorph(*jack);
		delete jack;
		Sorcerer s_test1("s_test1", "s_test1");
		Sorcerer s_test2("s_test2", "s_test2");
		std::cout<< "----------operator-----------" << std::endl;
		Victim test1("test1");
		Peon test2("test2");
		test1 = test2;
		s_test1 = s_test2;
		std::cout<< "----------end_operator-----------" << std::endl;
		std::cout<< "----------COPYING-----------" << std::endl;
		Sorcerer	copy1(s_test1);
		Victim		copy2(test1);
		Peon		copy3(test2);
		std::cout<< "----------END_COPYING-----------" << std::endl;
	}
	return 0; 
}