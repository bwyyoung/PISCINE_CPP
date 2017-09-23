/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:20:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/07/09 14:21:42 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __BULLET__
#define __BULLET__

#include "Object.hpp"

class Bullet : public Object
{
public:
	//Coplein
	Bullet(void);
	Bullet(Bullet const & src);
	Bullet & operator=(Bullet const & src);
	~Bullet(void);
	std::string		render() const;
	void			update();
	void			collideAction(IEntity *other_entity);
	void			get_color(int *arr);
private:
};

#endif
