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

#include "Base.hpp"

Base*		generate(void)
{
	Base	*ptr;
	int		i = std::rand() % 3;
	switch (i)
	{
		case 0:
			std::cout << "Generate-A" << std::endl;
			ptr = new A();
			break;
		case 1:
			std::cout << "Generate-B" << std::endl;
			ptr = new B();
			break;
		case 2:
			std::cout << "Generate-C" << std::endl;
			ptr = new C();
			break;
	}
	return (ptr);
}

void		identify_from_pointer( Base * p )
{
	if(B* test = dynamic_cast<B*>(p))
	{
		static_cast<void>(test);
		std::cout << "B" << std::endl;
	}
	else if(A* test = dynamic_cast<A*>(p))
	{
		static_cast<void>(test);
		std::cout << "A" << std::endl;
	}
	else if(C* test = dynamic_cast<C*>(p))
	{
		static_cast<void>(test);
		std::cout << "C" << std::endl;
	}
}

void		identify_from_reference( Base & p )
{
	if(B* test = dynamic_cast<B*>(&p))
	{
		static_cast<void>(test);
		std::cout << "B" << std::endl;
	}
	else if(A* test = dynamic_cast<A*>(&p))
	{
		static_cast<void>(test);
		std::cout << "A" << std::endl;
	}
	else if(C* test = dynamic_cast<C*>(&p))
	{
		static_cast<void>(test);
		std::cout << "C" << std::endl;
	}
}

int			main(void)
{
	int		test_num = 5;
	int		i = -1;
	std::srand(static_cast<unsigned int>(time(NULL)));
	while (++i < test_num)
	{
		std::cout << "TEST: " << std::to_string(i) << std::endl;
		Base	*test = generate();
		identify_from_pointer(test);
		identify_from_reference(*test);
		delete test;
	}
}