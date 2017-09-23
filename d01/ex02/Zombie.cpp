/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
	std::cout << "Zombie Spawn: "<< name <<" (" <<type << ") "<< std::endl;
	return;
}

Zombie::~Zombie()
{
	std::cout << "Zombie Dies: "<< this->_name << " ("<< this->_type <<") "
			<< std::endl;
	return;
}

void Zombie::announce() const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")>"
			<< " Braiiiiiiinnnssss..." << std::endl;
}
