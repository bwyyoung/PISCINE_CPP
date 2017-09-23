/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntity.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IENTITY_HPP
#define IENTITY_HPP

#include <iostream>
#include <cstdlib>

#define ENTITY_BULLET "BULLET"
#define ENTITY_PLAYER "PLAYER"
#define ENTITY_ENEMY "ENEMY"
#define ENTITY_STAR "STAR"
#define ENTITY_POWERUP "POWERUP"

class		IEntity
{
	/**
	 * All enemies and players have an EVENT
	 * when collided into.
	 * This is the most common shared function among all entities...
	**/
public:
	// std::string	render() const :
	// "^" --> Player
	// "!" --> Bullet
	// "M" --> Enemy
	// "." --> background stars
	virtual 			~IEntity() {};
	virtual std::string	render() const			= 0;
	virtual int			getX() const 			= 0;
	virtual int			getY() const 			= 0;
	virtual bool		isActive() const		= 0;
	virtual std::string	getType() const 		= 0;

	virtual void		activate(int x, int y)	= 0; // activate the entity into play
	virtual void		deactivate()			= 0;
	virtual void		collideAction(IEntity *other_entity) = 0;
	virtual void		update() 				= 0;
	virtual void		get_color(int *arr)		= 0;

};

#endif
