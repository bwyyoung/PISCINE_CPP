/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "MGR_Game.hpp"


Enemy::Enemy() : Ship(ENTITY_ENEMY)
{
	this->_x = 0;
	this->_y = 0;
}

Enemy::Enemy(int x, int y) : Ship(ENTITY_ENEMY)
{
	this->_x = x;
	this->_y = y;
}

Enemy::Enemy(Enemy const &src) : Ship(src)
{
	*this = src;
}

Enemy &Enemy::operator=(Enemy const &src)
{
	if (this == &src)
		return *this;
	_visibility = src._visibility;
	_type = src._type;
	this->_x = src._x;
	this->_y = src._y;
	return (*this);
}

Enemy::~Enemy(void)
{

}

void	Enemy::genMov(void)
{
	_y++;

	if(	_y >= WORLD_HEIGHT)
		_visibility = false;
}

std::string	Enemy::render() const
{
	return "V";
}

void		Enemy::update()
{
	this->genMov();
}

void		Enemy::collideAction(IEntity *other_entity)
{
	if (other_entity->getType() == ENTITY_PLAYER)
	{
		if (this->isActive())
			MGR_Game::getInstance()->increaseScore(-10);
		this->deactivate();
		other_entity->deactivate();
	}
	else if (other_entity->getType() == ENTITY_BULLET)
	{
		if (isActive())
			MGR_Game::getInstance()->increaseScore(1);
		this->deactivate();
		other_entity->deactivate();
	}
	else if (other_entity->getType() == ENTITY_POWERUP)
	{
		other_entity->deactivate();
	}
}

void	Enemy::get_color(int	*arr)
{
	arr[0] = 3;
	arr[1] = 0;
	arr[2] = 2;
}