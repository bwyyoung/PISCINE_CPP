/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

#ifndef _AMATERIA_
#define _AMATERIA_

#define TYPE_ICE "ice"
#define TYPE_CURE "cure"
#define NUM_MATERIA 4

class						ICharacter;

class						AMateria
{
protected:
	AMateria(void);
	std::string				type;
	unsigned int			xp_;
public:
	AMateria(std::string const & type);
	AMateria(AMateria const & src);
	AMateria&			operator=(AMateria const & rhs);
	virtual				~AMateria();
	std::string const	&getType() const; //Returns the materia type
	unsigned int		getXP() const; //Returns the Materia's XP
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif