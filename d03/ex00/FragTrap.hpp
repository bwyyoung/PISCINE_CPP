/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP__
#define __FRAGTRAP__

#include <iostream>
#include <string>
#include <stdlib.h>

#define DEBUG 1
#define NRG_VATS 25

class FragTrap
{
private:
	FragTrap(void);
public:
	void		init(std::string name);
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap&	operator=(FragTrap const & rhs);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		vaulthunter_dot_exe(std::string const & target);
private:
	int			Hit_Points;
	int			Hit_Points_Max;
	int			Energy_Points;
	int			Energy_Points_Max;
	int 		Level;
	std::string	Name;
	size_t		DMG_Melee;
	size_t		DMG_Ranged;
	int			DMR_Armor_Re;
	static const char* const	attacks[5];
	void		(FragTrap::*attack_ptr[2])(std::string const & target);
};

#endif