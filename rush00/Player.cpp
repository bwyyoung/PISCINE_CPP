/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "MGR_Game.hpp"

Player::Player(void) : Ship(ENTITY_PLAYER)
{
	is_powered_up = false;
}

Player::Player(Player const & src) : Ship(src)
{
	*this = src;
}

Player & Player::operator=(Player const & src)  // why not  " = 0 " ?
{
	if (this == &src)
		return *this;
	_visibility = false;
	_type = src._type;
	_x = src._x;
	_y = src._y;
	return (*this);
}

Player::~Player(void)
{

}

void	Player::move(int mv)
{
	int dx=0, dy=0;
	int		final_x;
	int		final_y;
	switch (mv)
	{
		case PLAYER_MOVE_UP:
			dx = 0;
			dy = -1;
			break;
		case PLAYER_MOVE_DOWN:
			dx = 0;
			dy = 1;
			break;
		case PLAYER_MOVE_LEFT:
			dx = -1;
			dy = 0;
			break;
		case PLAYER_MOVE_RIGHT:
			dx = 1;
			dy = 0;
			break;
	}
	final_x = _x + dx;
	final_y = _y + dy;

	if (is_powered_up)
		if (final_x - 1 < 0 || final_x + 1 >= WORLD_WIDTH)
			return;

	if (final_x < WORLD_WIDTH && final_x >= 0)
		_x += dx;
	if (final_y< WORLD_HEIGHT && final_y >= 0)
		_y += dy;
}

std::string	Player::render() const
{
	return "^";
}

void	Player::collideAction(IEntity *other_entity)
{
	if (other_entity->getType() == ENTITY_ENEMY)
	{
		if (this->isActive())
			MGR_Game::getInstance()->increaseScore(-10);
		this->deactivate();
		other_entity->deactivate();
	}
	else if (other_entity->getType() == ENTITY_POWERUP)
	{
		this->POWER_UP();
		other_entity->deactivate();
	}
	else if (other_entity->getType() == ENTITY_BULLET)
		other_entity->deactivate();
}

bool	Player::powered_up()
{
	return 	is_powered_up;
}

void	Player::POWER_UP()
{
	MGR_Game::getInstance()->increaseScore(5);
	is_powered_up = true;
}

void 	Player::deactivate()
{
	Ship::deactivate();
	is_powered_up = false;
}

Bullet	*Player::shoot()
{
	Bullet *m = MGR_Game::getInstance()->spawn_bullet();
	if (m)
	{
		m->activate(this->getX(), this->getY() - 1);
		return (m);
	}
	return (NULL);
}

void	Player::get_color(int	*arr)
{
	arr[0] = 1;
	arr[1] = 0;
	arr[2] = 3;
}