/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:26:23 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 13:25:52 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_HPP
#define SHIP_HPP

#include "IEntity.hpp"


//temporary variable
//#define WINDOW_X_MIN	MGR_Game::getinstance()->get_map_min_x()
//#define WINDOW_X_MAX	MGR_Game::getinstance()->get_map_max_x()
//#define WINDOW_Y_MIN	MGR_Game::getinstance()->get_map_min_y()
//#define WINDOW_Y_MAX	MGR_Game::getinstance()->get_map_max_y()

class Ship : public IEntity
{
	public:
		//Coplein
		Ship(std::string type);
		Ship(Ship const & src);
		Ship 		&operator=(Ship const & src);
		~Ship(void);

		std::string	render() const;

		int			getDmg() const;
		int			getArmor() const;
		int			getAmmo() const;
		int			getX() const;
		int			getY() const;
		bool		isActive() const;
		std::string	getType() const;


		void		activate(int x, int y); // activate the entity into play
		void		deactivate();
		void		update();
		void		collideAction(IEntity *other_entity);
		void		setDmg(int amount);
		void		setArmor(int amount);
		void		setAmmo(int amount);
		void		get_color(int *arr);

	protected:

		int				_x;
		int				_y;
		int				_dmg;
		int				_armor;
		int				_ammo;
		std::string		_type;
		bool 			_visibility; // is visible and active
};

#endif
