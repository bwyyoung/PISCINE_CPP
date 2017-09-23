/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < NUM_MATERIA; i++)
	{
		this->materia_slot[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{

}

MateriaSource&		MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this == &rhs)
		return *this;
	return (*this);
}

void				MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < NUM_MATERIA; i++)
	{
		if (this->materia_slot[i] == NULL)
		{
			this->materia_slot[i] = m->clone();
			return ;
		}
	}
}

AMateria*			MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < NUM_MATERIA; i++)
	{
		if (this->materia_slot[i] != NULL)
			if (this->materia_slot[i]->getType() == type)
				return this->materia_slot[i]->clone();
	}
	return (0);
}