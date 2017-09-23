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

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int main(void)
{
	ZombieEvent event = ZombieEvent();
	ZombieEvent event2 = ZombieEvent();
	event.setZombieType("Walkers");
	event2.setZombieType("Infected");

	Zombie *z6 = event2.randomChump();
	Zombie *z7 = event2.randomChump();
	Zombie *z8 = event2.randomChump();

	Zombie *z1 = event.newZombie("Alpha");
	Zombie *z2 = event.newZombie("Beta");
	Zombie *z3 = event.randomChump();
	Zombie *z4 = event.randomChump();
	Zombie *z5 = event.randomChump();

	z1->announce();
	z2->announce();
	z3->announce();
	z4->announce();
	z5->announce();

	z6->announce();
	z7->announce();
	z8->announce();

	delete z1;
	delete z2;
	delete z3;
	delete z4;
	delete z5;
	delete z6;
	delete z7;
	delete z8;

	return (0);
}