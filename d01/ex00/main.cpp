/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2017/01/11 10:52:13 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheStack()
{
	Pony ponyStack2 = Pony("Copy Constructed");
	/*
	http://stackoverflow.com/questions/8754854/when-is-a-c-class-instantiated-on-the-stack
	You are initializing Pony via copy constructor to the temporary object.
	Pony (and the temporary) has automatic storage which you can consider
	being allocated on "the stack" if that makes you happy.

	Copy elision is allowed in this case, essentially optimizing it to MyClass
	myClass, however note that it cannot always do this,
	such as when the copy constructor is private.
	 */
	Pony ponyStack;
}

void	ponyOnTheHeap()
{
	Pony *ponyHeap;

	ponyHeap = new Pony("PonyHeap");
	delete ponyHeap;
}

int		main()
{
	std::cout << "ponyOnTheHeap START" << std::endl;
	ponyOnTheHeap();
	std::cout << "ponyOnTheHeap END" << std::endl;
	std::cout << "ponyOnTheStack START" << std::endl;
	ponyOnTheStack();
	std::cout << "ponyOnTheStack END" << std::endl;
	std::cout << "END PROGRAM" << std::endl;
	return (0);
}
