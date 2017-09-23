/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_HPP
# define STAR_HPP

# include "Object.hpp"

class Star : public Object
{
public:
	//Coplein
	Star(void);
	Star(int x, int y);
	Star(Star const &src);
	Star			&operator=(Star const &src);
	~Star(void);

	std::string		render() const;
	void			update();
	void			collideAction(IEntity *other_entity);
	void			get_color(int *arr);

};

#endif