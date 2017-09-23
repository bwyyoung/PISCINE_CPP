/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

Object::Object(void){
	_visibility = false;
}

Object::Object(std::string type)
{
	this->_visibility = false;
	this->_type = type;
}

Object::Object(int x, int y, std::string type)
{
	this->_x = x;
	this->_y = y;
	this->_visibility = false;
	this->_type = type;
}

Object::Object(Object const & src)
{
	*this = src;
}

Object::~Object(void)
{}

Object		&Object::operator=(Object const & src)
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

std::string		Object::getType() const
{
	return this->_type;
}

bool 		Object::isActive() const
{
	return this->_visibility;
}

void		Object::activate(int x, int y)
{// activate the entity into play
	this->_x = x;
	this->_y = y;
	this->_visibility = true;
}

void		Object::deactivate()
{
	this->_visibility = false;
}

int			Object::getX() const
{
	return this->_x;
}

int			Object::getY() const
{
	return this->_y;
}

std::string	Object::render() const
{
	return "OBJ";
}

void		Object::update()
{

}

void		Object::collideAction(IEntity *other_entity)
{
	(void)other_entity;
}

void	Object::get_color(int	*arr)
{
	(void)arr;
}