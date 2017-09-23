/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{

}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < NUM_MATERIA; i++)
	{
		this->materia_slot[i] = NULL;
	}
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character()
{

}

Character&				Character::operator=(Character const & rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < NUM_MATERIA; i++)
	{
		materia_slot[i] = rhs.materia_slot[i];
	}
	this->name = rhs.getName();
	return (*this);
}

std::string const &		Character::getName() const
{
	return this->name;
}

void					Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < NUM_MATERIA; i++)
	{
		//if (this->materia_slot[i] == m)
		//	return;
		if (this->materia_slot[i] == NULL)
		{
			this->materia_slot[i] = m;
			return;
		}
	}
}

void					Character::unequip(int idx)
{
	if (idx < 0 || idx >= NUM_MATERIA)
		return;
	if (this->materia_slot[idx] != NULL)
		this->materia_slot[idx] = NULL;
}

void					Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= NUM_MATERIA)
		return;
	if (this->materia_slot[idx] == NULL)
		return;
	this->materia_slot[idx]->use(target);
}