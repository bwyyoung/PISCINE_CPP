/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"


void	Human::meleeAttack(std::string const & target)
{
	std::cout << "Melee Attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "Ranged Attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "Intimidating Shout on " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target)
{
	int			i = -1;

	void (Human::*array_pointer[3])(std::string const & target) =
	{
			&Human::meleeAttack,
			&Human::rangedAttack,
			&Human::intimidatingShout
	};
	const std::string attack_key[3] = {
			"melee",
			"ranged",
			"intimidating"
	};
	while (++i < 3)
		if (attack_key[i] == action_name)
			(this->*array_pointer[i])(target);
}
