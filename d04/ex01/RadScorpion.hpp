/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RADSCORPION__
#define __RADSCORPION__

#include "Enemy.hpp"

class		RadScorpion : public Enemy
{
public:
	RadScorpion(void);
	RadScorpion(RadScorpion const & src);
	~RadScorpion();
	RadScorpion&	operator=(RadScorpion const & rhs);
protected:
};

#endif