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

#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

#define TEST_EXTRA 1

void	test_1(void)
{
	std::cout << "--------EXTRA_TEST----------" <<std::endl;
	{
		std::cout << "____Constructor_____" << std::endl;
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;
		ISquad* vlc = new Squad;

		std::cout << "____Index and count_____" << std::endl;
		std::cout << vlc->push(bob) << std::endl;
		std::cout << vlc->getCount() << std::endl;

		std::cout << "____Same Object_____" << std::endl;
		std::cout << vlc->push(jim) << std::endl;
		std::cout << vlc->getCount() << std::endl;
		std::cout << vlc->push(jim) << std::endl;
		std::cout << vlc->getCount() << std::endl;

		std::cout << "____New Object Index_____" << std::endl;
		std::cout << vlc->push(new AssaultTerminator) << std::endl;
		std::cout << vlc->push(new TacticalMarine) << std::endl;

		std::cout << vlc->getCount() << std::endl;

		std::cout << "____Attack_____" << std::endl;
		vlc->getUnit(0)->battleCry();
		vlc->getUnit(1)->battleCry();

		vlc->getUnit(0)->rangedAttack();
		vlc->getUnit(1)->rangedAttack();

		vlc->getUnit(0)->meleeAttack();
		vlc->getUnit(1)->meleeAttack();

		std::cout << "____Not Exist_____" << std::endl;
		std::cout << vlc->getUnit(8) << std::endl;

		std::cout << "____Delete_____" << std::endl;
		delete vlc;
		//delete bob;
		//delete jim;
	}
	std::cout << "____Test Subject_____" << std::endl;
	{
		ISpaceMarine* bob = new TacticalMarine;
		ISpaceMarine* jim = new AssaultTerminator;
		ISquad* vlc = new Squad;
		vlc->push(bob);
		vlc->push(jim);
		for (int i = 0; i < vlc->getCount(); ++i)
		{
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
		std::cout << "____Not Exist_____" << std::endl;
		std::cout << vlc->getUnit(2) << std::endl;
		std::cout << vlc->getUnit(3) << std::endl;

		delete vlc;
	}
}

int		main()
{
	ISpaceMarine*	bob = new TacticalMarine;
	ISpaceMarine*	jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	if (TEST_EXTRA)
		test_1();
	return 0;
}
/**
 ./a.out | cat -e
Tactical Marine ready for battle$
* teleports from space *$
For the holy PLOT !$
* attacks with bolter *$
* attacks with chainsword *$
This code is unclean. PURIFY IT !$
* does nothing *$
* attacks with chainfists *$
Aaargh ...$
I'll be back ...$
 * **/