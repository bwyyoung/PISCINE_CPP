/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(void)
{
	this->container = NULL;
}

Squad::Squad(Squad const & src)
{
	*this = src;
}

Squad::~Squad()
{
	this->destroy_container();
}

void	Squad::destroy_container()
{
	t_marines	*temp;
	t_marines	*current = this->container;
	while (current != NULL)
	{
		temp = current;
		delete current->ptr;
		current = current->next;
		delete temp;
	}
}

Squad&	Squad::operator=(Squad const & rhs)
{
	ISpaceMarine		*current_marine;
	if (this == &rhs)
		return *this;
	int	num_units = -1;
	this->destroy_container();
	while (++num_units < rhs.getCount())
	{
		current_marine = rhs.getUnit(num_units);
		this->push(current_marine->clone());
	}
	return (*this);
}

int					Squad::getCount() const
{
	t_marines	*current = this->container;
	int	num_units = 0;
	while (current != NULL)
	{
		num_units++;
		current = current->next;
	}
	return (num_units);
}

ISpaceMarine*		Squad::getUnit(int index) const
{
	int			i = -1;
	t_marines	*current = this->container;

	if (index < 0 || this->container == NULL)
		return NULL;
	while (++i < index)
	{
		if (current == NULL)
			return (NULL);
		current = current->next;
	}
	if (!current)
		return (NULL);
	return current->ptr;
}

bool				Squad::check_unit_inside(ISpaceMarine* new_unit)
{
	t_marines	*current = this->container;

	if (current == NULL)
		return false;
	while (current != NULL)
	{
		if (current->ptr == new_unit)
			return true;
		current = current->next;
	}
	return false;
}

int					Squad::push(ISpaceMarine* new_unit)
{
	t_marines	*current = this->container;

	if (!new_unit || this->check_unit_inside(new_unit))
		return (this->getCount());
	if (this->container == NULL)
	{
		this->container = new t_marines();
		this->container->ptr = new_unit;
		return (1);
	}
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			current = current->next;
			continue;
		}
		current->next = new t_marines();
		current->next->ptr = new_unit;
		break;
	}
	return (this->getCount());
}
