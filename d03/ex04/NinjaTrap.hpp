/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef __NINJATRAP__
#define __NINJATRAP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
private:
	NinjaTrap(void);
public:
	void		init(std::string name);
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap(void);
	NinjaTrap&	operator=(NinjaTrap const & rhs);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		ninjaShoebox(NinjaTrap & rhs);
	void		ninjaShoebox(ClapTrap & rhs);
	void		ninjaShoebox(FragTrap & rhs);
	void		ninjaShoebox(ScavTrap & rhs);

	const int&	g_Hit_Points() const;
	const int&	g_Hit_Points_Max() const;
	const int&	g_Energy_Points() const;
	const int&	g_Energy_Points_Max() const;
	const int&	g_Level() const;
	const std::string&	g_Name() const;
	const size_t&	g_DMG_Melee() const;
	const size_t&	g_DMG_Ranged() const;
	const int&	g_DMR_Armor_Re() const;
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