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

#include "ScavTrap.hpp"
#include "SuperTrap.hpp"

int		main(void)
{
	std::srand (time(NULL));
	{
		std::cout << "-------------FragTrap--" << std::endl;
		FragTrap	*test = new FragTrap("FragTrap");
		test->meleeAttack("Dummy 1");
		test->rangedAttack("Dummy 2");
		test->takeDamage(50);
		test->takeDamage(5);
		test->takeDamage(100);
		test->beRepaired(10);
		test->beRepaired(1000);
		test->beRepaired(1000);
		std::cout << "-------------FragTrap_vaulthunter_dot_exe--" << std::endl;
		test->vaulthunter_dot_exe("Weed");
		test->vaulthunter_dot_exe("Weed");
		test->vaulthunter_dot_exe("Weed");
		test->vaulthunter_dot_exe("Weed");
		test->vaulthunter_dot_exe("Weed");
		std::cout << "-------------ScavTrap--" << std::endl;
		ScavTrap	*test2 = new ScavTrap("ScavTrap");
		test2->takeDamage(50);
		test2->takeDamage(5);
		test2->takeDamage(100);
		test2->beRepaired(10);
		test2->beRepaired(1000);
		test2->beRepaired(1000);
		test2->challengeNewcomer();
		test2->challengeNewcomer();
		test2->challengeNewcomer();
		test2->challengeNewcomer();
		test2->challengeNewcomer();
		std::cout << "-------------ClapTrap--" << std::endl;
		ClapTrap	*test3 = new ClapTrap("ClapTrap");
		test3->meleeAttack("Dummy 1");
		test3->rangedAttack("Dummy 2");
		test3->takeDamage(50);
		test3->takeDamage(5);
		test3->takeDamage(100);
		test3->beRepaired(10);
		test3->beRepaired(1000);
		test3->beRepaired(1000);
		std::cout << "-------------NinjaTrap--" << std::endl;
		NinjaTrap	*test4 = new NinjaTrap("NinjaTrap");
		test4->meleeAttack("Dummy 1");
		test4->rangedAttack("Dummy 2");
		test4->takeDamage(50);
		test4->takeDamage(5);
		test4->takeDamage(100);
		test4->beRepaired(10);
		test4->beRepaired(1000);
		test4->beRepaired(1000);
		std::cout << "-------------ninjaShoebox--" << std::endl;
		test4->ninjaShoebox(*test);
		test4->ninjaShoebox(*test2);
		test4->ninjaShoebox(*test3);
		test4->ninjaShoebox(*test4);
		std::cout << "-------------SuperTrap--" << std::endl;
		SuperTrap	*test5 = new SuperTrap("SuperTrap");
		test5->meleeAttack("Dummy 1");
		test5->rangedAttack("Dummy 2");
		test5->takeDamage(50);
		test5->takeDamage(5);
		test5->takeDamage(100);
		test5->beRepaired(10);
		test5->beRepaired(1000);
		test5->beRepaired(1000);
		std::cout << "-------------SuperTrap_ninjaShoebox--" << std::endl;
		test5->ninjaShoebox(*test);
		test5->ninjaShoebox(*test2);
		test5->ninjaShoebox(*test3);
		test5->ninjaShoebox(*test4);
		std::cout << "-------------SuperTrap_vaulthunter_dot_exe--" << std::endl;
		test5->vaulthunter_dot_exe("Weed");
		test5->vaulthunter_dot_exe("Weed");
		test5->vaulthunter_dot_exe("Weed");
		test5->vaulthunter_dot_exe("Weed");
		test5->vaulthunter_dot_exe("Weed");
		std::cout << "-------------ASSIGNMENT TEST--" << std::endl;
		ClapTrap	*temp = new ClapTrap("Temp_ClapTrap");
		*test3 = *test;
		*test3 = *test2;
		*test3 = *test3;
		*test3 = *test4;
		*test3 = *test5;
		*test3 = *temp;
		std::cout << "-------------DEATH--" << std::endl;
		delete test;
		delete test2;
		delete test3;
		delete test4;
		delete test5;
		delete temp;
	}
	return (0);
}