/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "RadScorpion.hpp"
#include "Aweapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

void	test1()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	Enemy* c = new RadScorpion();
	Enemy* d = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	zaz->attack(c);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
	zaz->attack(d);
	std::cout << *zaz;
	zaz->attack(d);
	std::cout << *zaz;
	zaz->attack(d);
	std::cout << *zaz;
}

int main()
{
	{
		Character* zaz = new Character("zaz");
		std::cout << *zaz;
		Enemy* b = new RadScorpion();
		AWeapon* pr = new PlasmaRifle();
		AWeapon* pf = new PowerFist();
		zaz->equip(pr);
		std::cout << *zaz;
		zaz->equip(pf);
		zaz->attack(b);
		std::cout << *zaz;
		zaz->equip(pr);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
	}
	std::cout << "-------------------------------------" << std::endl;
	test1();
	return 0;
}