/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SUPERTRAP__
#define __SUPERTRAP__

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

#define DEBUG 0


class SuperTrap : public FragTrap, public NinjaTrap
{
private:
	SuperTrap(void);
public:
	void		init(std::string name);
	SuperTrap(std::string name);
	SuperTrap(SuperTrap const & src);
	~SuperTrap();
	SuperTrap&	operator=(SuperTrap const & rhs);
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	const int&	g_Hit_Points() const;
	const int&	g_Hit_Points_Max() const;
	const int&	g_Level() const;
	const std::string&	g_Name() const;
	const size_t&	g_DMG_Melee() const;
	const size_t&	g_DMG_Ranged() const;
	const int&	g_DMR_Armor_Re() const;

	/**
	 * we are using FragTrap Energy Points for vaulthunter_dot_exe,
	 * and THAT value is the one which will be deducted
	 * when calling the function.
	 * Nonetheless, we refer to NinjaTrap Energy Points as the
	 * FragTrap Points will be UPDATED into Ninjatrap after calling
	 * vaulthunter_dot_exe
	**/
	void		vaulthunter_dot_exe(std::string const & target);
	const int&	g_Energy_Points() const;
	const int&	g_Energy_Points_Max() const;
protected:
	int 		Level;
	std::string	Name;
};

#endif