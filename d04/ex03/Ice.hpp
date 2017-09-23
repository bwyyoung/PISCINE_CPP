/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE__
#define __ICE__

#include "ICharacter.hpp"

class						Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice const & src);
	~Ice();
	Ice&				operator=(Ice const & rhs);
	AMateria*					clone() const;
	void						use(ICharacter& target);
};


#endif