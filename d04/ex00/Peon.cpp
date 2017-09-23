/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"



Peon::Peon(void)
{

}

Peon::Peon(std::string name) : Victim(name)
{
	this->name = name;
	std::cout <<"Zog zog." << std::endl;
}

Peon::Peon(Peon const &src)
{
	*this = src;
}

Peon& Peon::operator=(Peon const &rhs)
{
	if (this == &rhs)
		return *this;
	this->name = rhs.name;
	return (*this);
}

Peon::~Peon()
{
	std::cout <<"Bleuark..."<<std::endl;
}

const std::string			Peon::get_name() const
{
	return	this->name;
}

std::ostream&		operator<<(std::ostream &o, Peon const & rhs)
{
	o << "I'm "<<rhs.get_name() << " and I like otters !" << std::endl;
	return (o);
}

void	Peon::getPolymorphed() const
{
	std::cout << this->get_name() <<
			  " has been turned into a pink pony !" << std::endl;
}
