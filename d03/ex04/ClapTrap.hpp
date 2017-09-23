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
	virtual ~ClapTrap();
	ClapTrap&	operator=(ClapTrap const & rhs);
	virtual void		rangedAttack(std::string const & target);
	virtual void		meleeAttack(std::string const & target);
	virtual void		takeDamage(unsigned int amount);
	virtual void		beRepaired(unsigned int amount);

	int					calc_dmg(int amount, int DMR_Armor_Re, int Hit_Points);
	int					calc_repair(int amount, int Hit_Points_Max, int Hit_Points);

	virtual const int&	g_Hit_Points() const;
	virtual const int&	g_Hit_Points_Max() const;
	virtual const int&	g_Energy_Points() const;
	virtual const int&	g_Energy_Points_Max() const;
	virtual const int&	g_Level() const;
	virtual const std::string&	g_Name() const;
	virtual const size_t&	g_DMG_Melee() const;
	virtual const size_t&	g_DMG_Ranged() const;
	virtual const int&	g_DMR_Armor_Re() const;
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