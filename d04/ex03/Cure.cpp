/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria(TYPE_CURE)
{
}

Cure::Cure(Cure const & src)
{
	*this = src;
}

Cure::~Cure()
{

}

Cure&		Cure::operator=(Cure const & rhs)
{
	if (this == &rhs)
		return *this;
	this->xp_ = rhs.getXP();
	this->type = rhs.getType();
	return (*this);
}


void		Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals "
			  << target.getName() <<"'s wounds *" <<std::endl;
}

AMateria*	Cure::clone() const
{
	AMateria	*copy = new Cure();
	return copy;
}