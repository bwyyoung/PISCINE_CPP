/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{

}

AMateria::AMateria(std::string const & type)
{
	this->xp_ = 0;
	this->type = type;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria::~AMateria()
{

}

std::string const	&AMateria::getType() const
{
	return this->type;
}

unsigned int		AMateria::getXP() const
{
	return this->xp_;
}

AMateria&			AMateria::operator=(AMateria const & rhs)
{
	if (this == &rhs)
		return *this;
	this->xp_ = rhs.getXP();
	this->type = rhs.getType();
	return (*this);
}

void				AMateria::use(ICharacter& target)
{
	this->xp_ += 10;
	(void)target;
}