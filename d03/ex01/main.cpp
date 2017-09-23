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
	std::cout << "--FRAGTRAP--" << std::endl;
	{
		FragTrap	test("Claptrap");
		FragTrap	test3("Claptrap3");
		FragTrap	*test2 = new FragTrap("Claptrap_Girl");
		FragTrap	clone(test);

		test.meleeAttack("Dummy 1");
		test.rangedAttack("Dummy 2");
		test.vaulthunter_dot_exe("Weed");
		test.vaulthunter_dot_exe("Weed");
		test.vaulthunter_dot_exe("Weed");
		test.vaulthunter_dot_exe("Weed");
		test.vaulthunter_dot_exe("Weed");
		test2->takeDamage(50);
		test2->takeDamage(5);
		test2->takeDamage(100);
		test2->beRepaired(10);
		test2->beRepaired(1000);
		test2->beRepaired(1000);
		test = *test2;
		delete test2;
	}
	std::cout << "--SCAVTRAP--" << std::endl;
	{
		ScavTrap	test("Scavtrap");
		ScavTrap	*test2 = new ScavTrap("Scavtrap_Girl");
		ScavTrap	clone(test);

		test.meleeAttack("Dummy 1");
		test.rangedAttack("Dummy 2");
		test.challengeNewcomer();
		test.challengeNewcomer();
		test.challengeNewcomer();
		test.challengeNewcomer();
		test.challengeNewcomer();
		test2->takeDamage(50);
		test2->takeDamage(5);
		test2->takeDamage(100);
		test2->beRepaired(10);
		test2->beRepaired(1000);
		test2->beRepaired(1000);
		test = *test2;
		delete test2;
	}
	return (0);
}