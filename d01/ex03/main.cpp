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

#include "ZombieHorde.hpp"
#include "Zombie.hpp"

int main(void)
{
	std::cout << "--------- STACK HORDE ---------" << std::endl;
	ZombieHorde		theHorde(10);
	ZombieHorde		theHorde2(-1);
	ZombieHorde		*dynamic_horde;

	theHorde.announce();
	std::cout << "--------- INVALID HORDE ---------" << std::endl;
	theHorde2.announce();
	std::cout << "--------- DYNAMIC HORDE ---------" << std::endl;
	dynamic_horde = new ZombieHorde(5);
	dynamic_horde->announce();
	std::cout << "--------- KILL DYNAMIC HORDE---------" << std::endl;
	delete(dynamic_horde);
	std::cout << "--------- DYNAMIC HORDE DEAD---------" << std::endl;
	std::cout << "--------- KILL STACK HORDE---------" << std::endl;
	return (0);
}
