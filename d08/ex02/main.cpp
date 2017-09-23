/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

void		mutant_test()
{
	std::cout << "_________MutantStack__________" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Top:" << mstack.top() << std::endl;

	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	s.push(20);
	std::cout << "Top: " << s.top() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
}

void		additional_test()
{
	std::cout << "_________MutantStack++__________" << std::endl;
	MutantStack<int> mstack;
	MutantStack<int> mstack2;
	mstack.push(5);
	mstack.push(17);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "__mstack current__" <<std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	it = mstack2.begin();
	ite = mstack2.end();
	std::cout << "__mstack2 current__" <<std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "~~~~~~~~~~ SWAP mstack mstack2 ~~~~~~~~~~" <<std::endl;
	mstack.swap(mstack2);
	std::cout << "__mstack current__" <<std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	it = mstack2.begin();
	ite = mstack2.end();
	std::cout << "__mstack2 current__" <<std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "~~~~~~~~~~ mstack = mstack2 ~~~~~~~~~~" <<std::endl;
	mstack = mstack2;
	std::cout << "__mstack current__" <<std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	it = mstack2.begin();
	ite = mstack2.end();
	std::cout << "__mstack2 current__" <<std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

}

void		list_test()
{
	std::cout << "_________LIST__________" << std::endl;
	std::list<int> mstack;
	mstack.push_front(5);
	mstack.push_front(17);
	std::cout << "Top: " << mstack.front() << std::endl;
	mstack.pop_front();
	std::cout << "Top: " << mstack.front() << std::endl;

	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push_front(3);
	mstack.push_front(5);
	mstack.push_front(737);
	mstack.push_front(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int			main(void)
{
	mutant_test();
	list_test();
	additional_test();
	return 0;
}