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

#include "ClapTrap.hpp"

#ifndef __FRAGTRAP__
#define __FRAGTRAP__

#define NRG_VATS 25

class FragTrap : public virtual ClapTrap
{
private:
	FragTrap(void);
public:
	void		init(std::string name);
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap&	operator=(FragTrap const & rhs);
	void		vaulthunter_dot_exe(std::string const & target);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

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
	static const char* const	attacks[5];
	void		(FragTrap::*attack_ptr[2])(std::string const & target);
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