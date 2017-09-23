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

#include "easyfind.hpp"

void		test_deque()
{
	std::cout << "-----------DEQUE TEST-----------" << std::endl;
	// Create a deque containing integers
	std::deque<int> d;
	// Add an integer to the beginning and end of the deque
	d.push_front(2);
	d.push_back(10);
	try
	{
		std::cout << "trying to find 2" << std::endl;
		::easyfind(d, 2);
		std::cout << "trying to find 5" << std::endl;
		::easyfind(d, 5);
	}
	catch (std::invalid_argument s)
	{
		std::cout << s.what() << std::endl;
	}
}

void		test_vector()
{
	std::cout << "-----------VECTOR TEST-----------" << std::endl;
	std::vector<int> v(5);
	v[0] = 1;
	v[1] = 6;
	v[2] = 3;
	v[3] = 3;
	v[4] = 2;
	try
	{
		std::cout << "values of vector: " << v[0] << " "
				  << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << std::endl;
		std::cout << "trying to find 2" << std::endl;
		::easyfind(v, 2);
		std::cout << "trying to find 5" << std::endl;
		::easyfind(v, 5);
	}
	catch (std::invalid_argument s)
	{
		std::cout << s.what() << std::endl;
	}
}

void		test_list()
{
	std::cout << "-----------LIST TEST-----------" << std::endl;
	try
	{
		{
			std::list<int> second(4, 2);
			std::cout << "trying to find 2" << std::endl;
			::easyfind(second, 2);
			std::cout << "trying to find 5" << std::endl;
			::easyfind(second, 5);
		}
		{
			std::list<double> second(4, 2);
			std::cout << "trying to find 2" << std::endl;
			::easyfind(second, 2);
		}
	}
	catch (std::invalid_argument s)
	{
		std::cout << s.what() << std::endl;
	}

}

void		test_stack_queue()
{
	std::cout << "-----------STACK QUEUE TEST-----------" << std::endl;
	try
	{
		{
			std::stack<int> stack_test;         // stack initialized to copy of deque
			stack_test.push(2);
			stack_test.push(10);
			::easyfind(stack_test, 10);
			::easyfind(stack_test, 2);
			std::queue<int> queue_test;         // stack initialized to copy of deque
			queue_test.push(2);
			queue_test.push(10);
			::easyfind(queue_test, 10);
			::easyfind(queue_test, 2);
		}
	}
	catch (std::invalid_argument s)
	{
		std::cout << s.what() << std::endl;
	}
}

void		test_priority_queue()
{
	std::cout << "-----------PRIORITY QUEUE TEST-----------" << std::endl;
	try
	{
		{
			std::priority_queue<int> q;
			q.push(2);
			q.push(10);
			::easyfind(q, 10);
			::easyfind(q, 2);
		}
	}
	catch (std::invalid_argument s)
	{
		std::cout << s.what() << std::endl;
	}
}

int			main(void)
{
	test_vector();
	test_list();
	test_deque();
	test_stack_queue();
	test_priority_queue();
	return 0;
}