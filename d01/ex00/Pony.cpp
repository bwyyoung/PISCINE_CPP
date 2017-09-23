/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name)
{
	this->name = name;
	std::cout << "Pony Create: " << this->name << std::endl;
}

Pony::Pony()
{
	this->name = "DEFAULT(No Param)";
	std::cout << "Pony Create: " << this->name << std::endl;
}

Pony::~Pony()
{
	std::cout << "Pony Destroy: " << this->name << std::endl;
}