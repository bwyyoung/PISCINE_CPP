/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character(std::string const & name)
{
	this->name = name;
	this->ap = AP_LIMIT;
	this->weapon = NULL;
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character()
{

}

Character&			Character::operator=(Character const & rhs)
{
	if (this == &rhs)
		return *this;
	this->name = rhs.name;
	this->weapon = rhs.weapon;
	this->ap = rhs.ap;
	return (*this);
}

Character::Character(void)
{

}

void				Character::recoverAP()
{
	this->ap += AP_LIMIT;
	if (this->ap > AP_LIMIT)
		this->ap = AP_LIMIT;
}

void				Character::equip(AWeapon* theweapon)
{
	this->weapon = theweapon;
}

void				Character::attack(Enemy* theenemy)
{
	if (!theenemy || !this->weapon)
		return ;
	if ((this->ap - this->weapon->getAPCost()) < 0)
		return ;
	this->ap -= this->weapon->getAPCost();
	if (this->ap < 0)
		this->ap = 0;
	std::cout << getName() << " attacks " << theenemy->getType() << " with a "
		<< this->weapon->get_name() << std::endl;
	this->weapon->attack();
	theenemy->takeDamage(this->weapon->getDamage());
	if (theenemy->getHP() <= 0)
		delete theenemy;

}

std::string const	Character::getName() const
{
	return this->name;
}


std::ostream&		operator<<(std::ostream &o, Character const & rhs)
{
	if (rhs.has_weapon())
		o << rhs.getName() << " has "
		<< rhs.getAP() << " AP and wields a "
		<< rhs.getWeapon_Name() << std::endl;
	else
		o << rhs.getName() << " has "
		  << rhs.getAP() << " AP and is unarmed" << std::endl;
	return (o);
}
int					Character::getAP() const
{
	return this->ap;
}

std::string const	Character::getWeapon_Name() const
{
	return this->weapon->get_name();
}

bool				Character::has_weapon()const
{
	return (this->weapon != NULL);
}