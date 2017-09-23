/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __CURE__
#define __CURE__

#include "ICharacter.hpp"

class						Cure : public AMateria
{
public:
	Cure(void);
	Cure(Cure const & src);
	Cure&				operator=(Cure const & rhs);
	~Cure();
	AMateria*					clone() const;
	void						use(ICharacter& target);
};

#endif