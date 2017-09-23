/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"


Enemy::Enemy(int hp, std::string const & type)
{
	this->hp = hp;
	this->type = type;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy()
{

}

Enemy&	Enemy::operator=(Enemy const & rhs)
{
	if (this == &rhs)
		return *this;
	this->hp = rhs.hp;
	this->type = rhs.type;
	return (*this);
}

std::string	const	Enemy::getType() const
{
	return this->type;
}

int					Enemy::getHP() const
{
	return this->hp;
}

void				Enemy::takeDamage(int a)
{
	if (a < 0)
		return ;
	this->hp -= a;
	if (this->hp < 0)
		this->hp = 0;
}

Enemy::Enemy(void)
{

}