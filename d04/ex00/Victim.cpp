/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"


Victim::Victim(void)
{

}

Victim::Victim(std::string name)
{
	this->name = name;
	std::cout <<"Some random victim called "
			<< this->name <<" just popped !"<< std::endl;
}

Victim::Victim(Victim const &src)
{
	*this = src;
}

Victim& Victim::operator=(Victim const &rhs)
{
	if (this == &rhs)
		return *this;
	this->name = rhs.name;
	return (*this);
}

Victim::~Victim()
{
	std::cout <<"Victim "<< this->get_name() <<
			  " just died for no apparent reason !" << std::endl;
}

const std::string			Victim::get_name() const
{
	return	this->name;
}

std::ostream&		operator<<(std::ostream &o, Victim const & rhs)
{
	o << "I'm "<<rhs.get_name() << " and I like otters !" << std::endl;
	return (o);
}

void	Victim::getPolymorphed() const
{
	std::cout << this->get_name() <<
				" has been turned into a cute little sheep !" << std::endl;
}
