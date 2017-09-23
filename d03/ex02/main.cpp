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

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	std::srand (time(NULL));
	{
		std::cout << "-------------FragTrap--" << std::endl;
		FragTrap	*test = new FragTrap("FragTrap");
		test->meleeAttack("Dummy 1");
		test->rangedAttack("Dummy 2");
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
		*test3 = *test2;
		*test3 = *test;
		*test3 = *test3;
		std::cout << "-------------DEATH--" << std::endl;
		delete test2;
		delete test;
		delete test3;
	}
	return (0);
}