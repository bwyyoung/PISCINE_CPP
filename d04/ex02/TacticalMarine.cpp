/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
	*this = src;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine&		TacticalMarine::operator=(TacticalMarine const & rhs)
{
	if (this == &rhs)
		return *this;
	return (*this);
}

ISpaceMarine		*TacticalMarine::clone() const
{
	TacticalMarine	*new_marine;

	new_marine = new TacticalMarine();
	return new_marine;
}

void				TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT !" << std::endl;
}

void				TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void				TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with chainsword *" << std::endl;

}