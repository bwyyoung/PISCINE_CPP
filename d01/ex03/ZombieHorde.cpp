/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"



ZombieHorde::ZombieHorde(int N)
{
	int	name_id;
	int	horde_id;

	num_zombies = N;
	if (N <= 0)
		return ;
	this->_initNames();
	num_zombies = N;
	my_zombies = new Zombie[num_zombies];
	horde_id = std::rand() % 100;

	for (int i = 0; i < num_zombies; i++)
	{
		name_id = std::rand() % 10;
		my_zombies[i].init(_arrNames[name_id], "ZombieHorde_"
						+ std::to_string(horde_id));
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] my_zombies;
}

void	ZombieHorde::announce()
{
	if (num_zombies <= 0)
		return ;
	for (int i = 0; i < num_zombies; i++)
	{
		my_zombies[i].announce();
	}
}

void	ZombieHorde::_initNames()
{
	_arrNames[0] = "A";
	_arrNames[1] = "B";
	_arrNames[2] = "C";
	_arrNames[3] = "D";
	_arrNames[4] = "E";
	_arrNames[5] = "F";
	_arrNames[6] = "G";
	_arrNames[7] = "H";
	_arrNames[8] = "I";
	_arrNames[9] = "J";
}