/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int		main(int argc, char **argv)
{
	std::string		noinput = "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";

	if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
		{
			for (size_t j = 0; j < std::strlen(argv[i]); j++)
				argv[i][j] = std::toupper(argv[i][j], std::locale());
			std::cout << argv[i];
		}
		std::cout << "\n";
		return (1);
	}
	std::cout << noinput;
	return (1);
}