/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP__
#define __CLAPTRAP__

#include <iostream>
#include <string>
#include <stdlib.h>

#define DEBUG 0


class ClapTrap
{
private:
	ClapTrap(void);
public:
	void		init(std::string name);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap();
	ClapTrap&	operator=(ClapTrap const & rhs);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
protected:
	int			Hit_Points;
	int			Hit_Points_Max;
	int			Energy_Points;
	int			Energy_Points_Max;
	int 		Level;
	std::string	Name;
	size_t		DMG_Melee;
	size_t		DMG_Ranged;
	int			DMR_Armor_Re;
};

#endif