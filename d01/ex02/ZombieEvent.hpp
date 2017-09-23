/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string		_zombieType;
	std::string		_arrNames[10];
	void			_initNames();
public:
	ZombieEvent();
	ZombieEvent(std::string zombieType);
	~ZombieEvent();
	void			setZombieType(std::string zombieType);
	Zombie			*newZombie(std::string name);
	Zombie			*randomChump();
};

#endif
