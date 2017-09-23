/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)
{

}

Sorcerer::Sorcerer(std::string name, std::string title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name <<", "<< this->title <<", is born !"<< std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;
}

Sorcerer& Sorcerer::operator=(Sorcerer const &rhs)
{
	if (this == &rhs)
		return *this;
	this->name = rhs.name;
	this->title =  rhs.title;
	return (*this);
}

Sorcerer::~Sorcerer()
{
	std::cout << this->get_name_title() <<
	"is dead. Consequences will never be the same !" << std::endl;
}

const std::string			Sorcerer::get_name() const
{
	return	this->name;
}

const std::string			Sorcerer::get_title() const
{
	return	this->title;
}

const std::string			Sorcerer::get_name_title() const
{
	return (this->get_name() + ", " + this->get_title() + ", ");
}

std::ostream&		operator<<(std::ostream &o, Sorcerer const & rhs)
{
	o << "I am "<<rhs.get_name_title() << "and I like ponies !" << std::endl;
	return (o);
}

void				Sorcerer::polymorph(Victim const &item) const
{
	item.getPolymorphed();
}
