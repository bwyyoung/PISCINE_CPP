/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:50:38 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:22:00 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Ship.hpp"
#include "Bullet.hpp"

#define PLAYER_MOVE_UP 		1
#define PLAYER_MOVE_DOWN	2
#define PLAYER_MOVE_LEFT	3
#define PLAYER_MOVE_RIGHT	4

class Player : public Ship
{
	public:
	//Coplein
		Player(void);
		Player(Player const & src);
		Player & operator=(Player const & src);
		~Player(void);

		std::string	render() const;
		int			getScore() const;

		//void		update(); unused
		void		collideAction(IEntity *other_entity);
		Bullet		*shoot();
		void		get_color(int*);

		void		move(int mv);
		bool		powered_up();
		void		POWER_UP();
		void		deactivate();
	private:
		bool		is_powered_up;
};



#endif
