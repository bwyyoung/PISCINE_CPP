/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:26:23 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 13:25:52 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ship.hpp"

Ship::Ship(std::string type) : _type(type), _visibility(false)
{}

Ship::Ship(Ship const & src) : _type(src._type), _visibility(false)
{
	*this = src;
}

Ship::~Ship(void)
{}

Ship 		&Ship::operator=(Ship const & src)
{
	if (this == &src)
		return *this;
	this->_type = src._type;
	this->_visibility = src._visibility;
	this->_x = src._x;
	this->_y = src._y;
	return (*this);
}


int		Ship::getDmg() const{ return this->_dmg; }
int		Ship::getArmor() const { return this->_armor; }
int		Ship::getAmmo() const { return this->_ammo; }
int		Ship::getX() const { return this->_x; }
int		Ship::getY() const { return this->_y; }
bool	Ship::isActive() const { return this->_visibility; }
std::string	Ship::getType() const { return this->_type; }


void	Ship::setDmg(int amount) { this->_dmg = amount;}
void	Ship::setArmor(int amount) { this->_armor = amount;}
void	Ship::setAmmo(int amount) { this->_ammo = amount;}

void	Ship::activate(int x, int y)
{// activate the entity into play
	this->_x = x;
	this->_y = y;
	this->_visibility = true;
}
void	Ship::deactivate()
{
	this->_visibility = false;
}

void	Ship::update()
{

}

void		Ship::collideAction(IEntity *other_entity)
{
	(void)other_entity;
}

std::string	Ship::render() const
{
	return "S";
}

void		Ship::get_color(int	*arr)
{
	(void)arr;
}
