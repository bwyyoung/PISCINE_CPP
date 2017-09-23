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

#include "mindopen.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		return (0);
	try
	{
		Mindopen::getInstance()->open_program_file(argv[1]);
		if (argc == 3)
			Mindopen::getInstance()->open_input_file(argv[2]);
		Mindopen::getInstance()->execute_program();
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

