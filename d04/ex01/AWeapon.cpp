/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}

AWeapon::~AWeapon()
{

}

AWeapon&	AWeapon::operator=(AWeapon const & rhs)
{
	if (this == &rhs)
		return *this;
	this->name = rhs.name;
	this->apcost =  rhs.apcost;
	this->damage =  rhs.damage;
	return (*this);
}

const std::string	AWeapon::get_name() const
{
	return this->name;
}

int					AWeapon::getAPCost() const
{
	return this->apcost;
}
int					AWeapon::getDamage() const
{
	return this->damage;
}

AWeapon::AWeapon(void)
{

}
