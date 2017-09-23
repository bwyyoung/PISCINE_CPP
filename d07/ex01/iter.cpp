/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class	printer
{
public:
	static void	print_template(T b)
	{
		std::cout <<"print_outsider_PRINTING "<< b << std::endl;
	}
};

void	print_int(int b)
{
	std::cout <<"print_int_PRINTING "<< b << std::endl;
}

void	print_string(std::string b)
{
	std::cout <<"print_string_PRINTING "<< b << std::endl;
}

template <typename T>
void	print_outsider(T b)
{
	std::cout <<"print_outsider_PRINTING "<< b << std::endl;
}


template <typename T, typename F>
void	iter(T *addr_array, int arr_length, F f)
{
	int		i = -1;
	if (!addr_array)
		return;
	while (++i < arr_length)
		f(addr_array[i]);
}

void	test(int a)
{
	a++;
}

int		main(void)
{
	void	(*b)(int) = &printer<int>::print_template;
	void	(*c)(std::string) = &printer<std::string>::print_template;
	int arrInt[] = {42, 123, 543, 423, 98};
	std::string arrString[] = {"ok", "Yes", "Hey", "Yeah", "HO"};
	std::cout << "----instantiated int function template------" << std::endl;
	::iter(arrInt, 5, b);
	std::cout << "----instantiated string function template------" << std::endl;
	::iter(arrString, 5, c);
	std::cout << "----string_outsider function------" << std::endl;
	void	(*ptr)(std::string) = print_outsider;
	::iter(arrString, 5, ptr);
	std::cout << "----int_outsider function------" << std::endl;
	void	(*ptr1)(int) = print_outsider;
	::iter(arrInt, 5, ptr1);
	std::cout << "----int function------" << std::endl;
	::iter(arrInt, 5, print_int);
	std::cout << "----string function------" << std::endl;
	::iter(arrString, 5, print_string);
	return 0;
}