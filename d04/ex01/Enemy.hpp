/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ENEMY__
#define __ENEMY__

#include <iostream>
#include <string>

class		Enemy
{
public:
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const & src);
	virtual	~Enemy();
	Enemy&	operator=(Enemy const & rhs);
	std::string const	getType() const;

	int					getHP() const;
	virtual void		takeDamage(int);
protected:
	Enemy(void);
	int			hp;
	std::string	type;
};

#endif