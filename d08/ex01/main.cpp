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

#include "span.hpp"

void		test_default()
{
	std::cout << "______________TEST_DEFAULT______________" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void		test_1()
{
	std::cout << "______________TEST_1______________" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout <<  "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout <<  "Shortest Span: " << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "____1 N Test___" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(3);
		try
		{
			std::cout <<  "Longest Span: " << sp.longestSpan() << std::endl;
			std::cout <<  "Shortest Span: " << sp.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "___5 N, 0 member Test___" << std::endl;
	{
		try
		{

			Span sp = Span(5);
			std::cout <<  "Longest Span: " << sp.longestSpan() << std::endl;
			std::cout <<  "Shortest Span: " << sp.shortestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "____> N Test___" << std::endl;
	{
		try
		{

			Span sp;
			sp.addNumber(0);
			sp.addNumber(-1);
			std::cout <<  "Longest Span: " << sp.longestSpan() << std::endl;
			std::cout <<  "Shortest Span: " << sp.shortestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "___Fibonnacci Test 10000____" << std::endl;
	{
		try
		{
			Span sp = Span(0, 10000);
			std::cout <<  "Longest Span: " << sp.longestSpan() << std::endl;
			std::cout <<  "Shortest Span: " << sp.shortestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "___std container test____" << std::endl;
	{
		int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
		int i = -1;
		std::vector<int> v;
		while (++i <= 12)
			v.push_back(arr[i]);

		try
		{
			Span sp = Span(20);

			sp.add_container(v);
			std::cout <<  "Longest Span: " << sp.longestSpan() << std::endl;
			std::cout <<  "Shortest Span: " << sp.shortestSpan() << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

int			main(void)
{
	test_default();
	test_1();
	return 0;
}