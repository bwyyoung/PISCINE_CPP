/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Powerup.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Powerup.hpp"
#include "MGR_Graphics.hpp"
#include "MGR_Game.hpp"

Powerup::Powerup(void) : Object(0, 0, ENTITY_POWERUP)
{
	isleft = std::rand() % 2;
	_visibility = false;
}

Powerup::Powerup(int x, int y) : Object(x, y, ENTITY_POWERUP)
{

}

Powerup::Powerup(Powerup const &rhs) : Object(rhs)
{
	*this = rhs;
}

Powerup::~Powerup(void)
{

}

bool 			Powerup::moving_left()
{
	return this->isleft;
}

void			Powerup::flip_direction()
{
	this->isleft = !this->isleft;
}

void			Powerup::move_sideways()
{
	if (isleft)
		this->_x--;
	else
		this->_x++;
}


Powerup			&Powerup::operator=(Powerup const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_visibility = rhs._visibility;
	_type = rhs._type;
	_x = rhs._x;
	_y = rhs._y;
	return (*this);
}

std::string		Powerup::render() const
{
	return "P";
}

void	Powerup::update()
{
	_y++;
	if(_y  >= WORLD_HEIGHT)
		_visibility = false;
}


void		Powerup::collideAction(IEntity * other_entity)
{
	if (other_entity->getType() == ENTITY_PLAYER)
	{
		if (this->isActive())
			MGR_Game::getInstance()->player_power_up();
		this->deactivate();
	}
	else if (other_entity->getType() == ENTITY_BULLET)
		other_entity->deactivate();
	else if (other_entity->getType() == ENTITY_ENEMY)
		other_entity->deactivate();
	else if (other_entity->getType() == ENTITY_POWERUP)
	{
		if (other_entity != this)
		other_entity->deactivate();
	}
}

void	Powerup::get_color(int	*arr)
{
	arr[0] = 5;
	arr[1] = 0;
	arr[2] = 5;
}