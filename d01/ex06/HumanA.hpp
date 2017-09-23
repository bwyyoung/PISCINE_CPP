/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2017/01/11 10:59:01 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_A__
#define __HUMAN_A__

#include "Weapon.hpp"

class	HumanA
{
public:
	HumanA(std::string name, Weapon &theweapon);
	HumanA(std::string name);
	~HumanA();
	void		attack();
	void		setWeapon(Weapon &theweapon);
private:
	std::string	name;
	Weapon		*weapon;
};

#endif
