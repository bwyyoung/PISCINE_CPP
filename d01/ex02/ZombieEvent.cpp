/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
	//seed our random number generator
	std::srand(std::time(NULL));
	ZombieEvent::_initNames();
	Zombie		z1("!! IT BEGINS", "ZombieEvent");
	std::cout << "New event" << std::endl;
	z1.announce();
	return;
}

ZombieEvent::ZombieEvent(std::string zombieType) : _zombieType(zombieType)
{
	std::cout << "New event type [" << this->_zombieType << "]" << std::endl;

	return;
}

ZombieEvent::~ZombieEvent()
{
	std::cout << "End event for "<< this->_zombieType << std::endl;
	return;
}

void ZombieEvent::_initNames()
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

void ZombieEvent::setZombieType(std::string zombieType)
{
	Zombie		z1("!! Set Event Zombie Announcer", "setZombieType");
	std::cout << "!! Set Event Zombie Type: " << zombieType << std::endl;
	z1.announce();
	this->_zombieType = zombieType;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(name, this->_zombieType));
}

Zombie *ZombieEvent::randomChump()
{
	int val;

	val = std::rand() % 10;
	return (new Zombie(_arrNames[val], this->_zombieType));
}
