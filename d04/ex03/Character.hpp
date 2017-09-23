 	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER__
#define __CHARACTER__

#include "ICharacter.hpp"


class		Character : public ICharacter
{
private:
	Character(void);
	AMateria				*materia_slot[NUM_MATERIA];
	std::string				name;
public:
	Character(std::string name);
	Character(Character const & src);
	Character&				operator=(Character const & rhs);
	~Character();
	std::string const &		getName() const;
	void					equip(AMateria* m);
	void					unequip(int idx);
	void					use(int idx, ICharacter& target);
};

#endif