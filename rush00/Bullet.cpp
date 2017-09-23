/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:20:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/07/09 14:21:42 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include "MGR_Graphics.hpp"
#include "Object.hpp"
#include "MGR_Game.hpp"


Bullet::Bullet(void) : Object(ENTITY_BULLET)
{}

Bullet::Bullet(Bullet const & src) : Object(src)
{
	*this = src;
}

Bullet::~Bullet(void)
{}

Bullet 		& Bullet::operator=(Bullet const & src)
{
	if (this == &src)
		return *this;
	this->_type = src._type;
	this->_x = src._x;
	this->_y = src._y;
	this->_dmg = src._dmg;
	this->_visibility = src._visibility;
	return (*this);
}



std::string     Bullet::render() const
{
	return "!";
}

void		Bullet::update()
{
	this->_y--;
	if (this->_y < 0)
		this->_visibility = false;
}

void		Bullet::collideAction(IEntity *other_entity)
{
	if(other_entity->getType()==ENTITY_ENEMY)
	{
		if (isActive())
			MGR_Game::getInstance()->increaseScore(1);
		this->deactivate();
		other_entity->deactivate();
	}
	else if(other_entity->getType()==ENTITY_POWERUP)
	{
		this->deactivate();
	}
}

void	Bullet::get_color(int	*arr)
{
	arr[0] = 2;
	arr[1] = 0;
	arr[2] = 1;
}