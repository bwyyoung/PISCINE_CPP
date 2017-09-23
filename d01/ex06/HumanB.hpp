/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2017/01/11 10:57:48 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_B__
#define __HUMAN_B__

#include "Weapon.hpp"

class	HumanB
{
public:
	HumanB(std::string name, Weapon &theweapon);
	HumanB(std::string name);
	~HumanB();
	void		attack();
	void		setWeapon(Weapon &theweapon);
private:
	std::string	name;
	Weapon		*weapon;
};

#endif
