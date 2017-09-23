/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:20:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/07/09 14:21:42 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "IEntity.hpp"

class Object : public IEntity
{
	public:
	//Coplein
		Object(void);
		Object(std::string type);
		Object(int x, int y, std::string type);
		Object(Object const & src);
		Object & operator=(Object const & src);
		~Object(void);


		Object &	operator+=(int amount);
		Object &	operator-=(int amount);


		int			getDmg() const;

		void		setDmg(int amount);
		void		setType(std::string t);

		std::string	render() const;
		int			getX() const;
		int			getY() const;
		bool 		isActive() const;
		std::string	getType() const;

		void		activate(int x, int y);
		void		deactivate();
		void		collideAction(IEntity *other_entity);
		void		update();
		void		get_color(int *arr);
protected:
		int 		_x;
		int 		_y;
		int 		_dmg;
		bool 		_visibility; // is visible and active
		std::string _type;
};

#endif
