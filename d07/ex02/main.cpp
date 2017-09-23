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

#include "Array.hpp"
#include <iostream>

int			main(void)
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	float arrf[] = {0.01f, 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.1f, 11.1f};
	int i = 0;
	Array<int> a(11);
	Array<float> b(10);

	std::cout << "a len: " << a.size() << std::endl;
	std::cout << "b len: " << b.size() << std::endl;
	while (i <= 12)
	{
		try
		{
			std::cout << "a index: " << i << "/" << a.size() << std::endl;
			std::cout << "b index: " << i << "/" << b.size() << std::endl;
			a[i] = arr[i];
			b[i] = arrf[i];
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		i++;
	}
	return (0);
}
