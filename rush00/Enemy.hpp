/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Ship.hpp"

class Enemy : public Ship
{
public:
	//Coplein
	Enemy(void);
	Enemy(int x, int y);
	Enemy(Enemy const &src);
	Enemy	&operator=(Enemy const &src);
	~Enemy(void);

	void		collideAction(IEntity *other_entity);
	void		update();
	std::string	render() const;
	void			get_color(int *arr);

	// Enemy movement...
	void		genMov();

//	Enemy &operator+=(int amount);

//	Enemy &operator-=(int amount);

};

#endif
