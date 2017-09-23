/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SUPERMUTANT__
#define __SUPERMUTANT__

#include "Enemy.hpp"

class		SuperMutant : public Enemy
{
public:
	SuperMutant(void);
	SuperMutant(SuperMutant const & src);
	~SuperMutant();
	SuperMutant&	operator=(SuperMutant const & rhs);
	void			takeDamage(int);
protected:
};

#endif