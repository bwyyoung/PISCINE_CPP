/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria(TYPE_ICE)
{

}

Ice::Ice(Ice const & src)
{
	*this = src;
}

Ice::~Ice()
{

}

Ice&		Ice::operator=(Ice const & rhs)
{
	if (this == &rhs)
		return *this;
	this->xp_ = rhs.getXP();
	this->type = rhs.getType();
	return (*this);
}

void		Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at "
			<< target.getName() <<" *" <<std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria	*copy = new Ice();
	return copy;
}