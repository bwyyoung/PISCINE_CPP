/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.hpp"
#include "MGR_Graphics.hpp"


Star::Star(void) : Object(0, 0, ENTITY_STAR)
{

}

Star::Star(int x, int y) : Object(x, y, ENTITY_STAR)
{

}

Star::Star(Star const &rhs) : Object(rhs)
{
	*this = rhs;
}

Star::~Star(void)
{

}

Star			&Star::operator=(Star const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_visibility = rhs._visibility;
	_type = rhs._type;
	_x = rhs._x;
	_y = rhs._y;
	return (*this);
}

std::string		Star::render() const
{
	return ".";
}

void	Star::update()
{
	_y++;
	if(_y  >= WORLD_HEIGHT)
		_visibility = false;
}


void		Star::collideAction(IEntity *)
{
	//nothing
}

void	Star::get_color(int	*arr)
{
	arr[0] = 6;
	arr[1] = 0;
	arr[2] = 4;
}