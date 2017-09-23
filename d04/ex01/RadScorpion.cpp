/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(RadScorpion const & src)
{
	*this = src;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;

}

RadScorpion&		RadScorpion::operator=(RadScorpion const & rhs)
{
	if (this == &rhs)
		return *this;
	this->hp = rhs.hp;
	this->type = rhs.type;
	return (*this);
}

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}