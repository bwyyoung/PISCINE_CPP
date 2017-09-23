/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Powerup.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERUP_HPP
# define POWERUP_HPP

# include "Object.hpp"

class Powerup : public Object
{
public:
	//Coplein
	Powerup(void);
	Powerup(int x, int y);
	Powerup(Powerup const &src);
	Powerup			&operator=(Powerup const &src);
	~Powerup(void);

	std::string		render() const;
	void			update();
	void			collideAction(IEntity *other_entity);
	void			get_color(int *arr);
	bool 			moving_left();
	void			flip_direction();
	void			move_sideways();
private:
	bool			isleft;
};

#endif