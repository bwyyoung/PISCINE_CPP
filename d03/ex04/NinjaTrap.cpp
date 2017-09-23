/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap("NO_NAME")
{
	this->init("NO_NAME");
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	this->init(name);
	return;
}

void NinjaTrap::init(std::string name)
{
	this->Name = name;
	this->Hit_Points = 60;
	this->Hit_Points_Max = 60;
	this->Energy_Points = 120;
	this->Energy_Points_Max = 120;
	this->Level = 1;
	this->DMG_Melee = 60;
	this->DMG_Ranged = 5;
	this->DMR_Armor_Re = 0;
	std::cout << this->Name << " -- start bootup sequence." << std::endl;
	std::cout << "Directive one: Protect humanity! Directive two: " <<
			"Obey Jack at all costs. Directive three: Ninja!" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	std::cout << src.Name
			<<": I can do more than open doors sir! We NINJ4-TP units can be "
			<<"programmed to do anything from open doors to ninja-sassinate "
			<<"highly important Janitory officials!" << std::endl;
	this->Name = "CloneTrap";
	*this = src;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	std::cout << this->Name << ": You. Are. Not. Dead! Your new designation is "
	<< "NINJ4-TP. NinjaTrap. You are a merciless killing machine. Got it?"
  	<< std::endl;
	return;
}

NinjaTrap&	NinjaTrap::operator=(NinjaTrap const & rhs)
{
	if (this == &rhs)
		return *this;
	std::cout << (this)->Name <<" & " << rhs.Name
	<< "->CLONE SCRIPT:\n" <<
	this->Name << ": If you really believe that then you "
	<<"should clone yourself while you're still alive."<<std::endl;
	std::cout<< rhs.Name << ": Why is that?"
	<< " So I can understand your unique perspective?"<<std::endl;
	std::cout<< this->Name <<": No. So you can go f*** yourself!"<<std::endl;

	this->Name = rhs.g_Name();
	this->Hit_Points = rhs.g_Hit_Points();
	this->Hit_Points_Max = rhs.g_Hit_Points_Max();
	this->Energy_Points = rhs.g_Energy_Points();
	this->Energy_Points_Max = rhs.g_Energy_Points_Max();
	this->Level = rhs.g_Level();
	this->DMG_Melee = rhs.g_DMG_Melee();
	this->DMG_Ranged = rhs.g_DMG_Ranged();
	this->DMR_Armor_Re = rhs.g_DMR_Armor_Re();
	return *this;
}

void		NinjaTrap::ninjaShoebox(ClapTrap & clap)
{
	clap.meleeAttack(this->Name);
	clap.rangedAttack(this->Name);
}

void		NinjaTrap::ninjaShoebox(NinjaTrap & ninja)
{
	ninja.meleeAttack(this->Name);
	ninja.rangedAttack(this->Name);
}

void		NinjaTrap::ninjaShoebox(FragTrap & frag)
{
	frag.meleeAttack(this->Name);
	frag.vaulthunter_dot_exe(this->Name);
}

void		NinjaTrap::ninjaShoebox(ScavTrap & scav)
{
	scav.rangedAttack(this->Name);
	scav.challengeNewcomer();
}

void		NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "NINJ4-TP "
			  << this->Name
			  << " attacks "
			  <<target
			  <<" at range, causing "
			  <<this->DMG_Ranged
			  <<" points of damage !" << std::endl;
}

void		NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "NINJ4-TP "
			  << this->Name
			  << " attacks "
			  <<target
			  <<" at melee, causing "
			  <<this->DMG_Melee
			  <<" points of damage !" << std::endl;
}

void		NinjaTrap::takeDamage(unsigned int amount)
{
	this->Hit_Points = calc_dmg(amount, this->DMR_Armor_Re, this->Hit_Points);
	std::cout << "NINJ4-TP "
			  << this->Name
			  << " takes "
			  << amount
			  <<" points of damage ! HP:"<< this->Hit_Points << std::endl;
}

void		NinjaTrap::beRepaired(unsigned int amount)
{
	this->Hit_Points = calc_repair(amount,
								   this->Hit_Points_Max, this->Hit_Points);
	std::cout << "NINJ4-TP "
			  << this->Name
			  << " takes "
			  << amount
			  <<" points of repair ! HP:"<< this->Hit_Points<< std::endl;
}
const int&			NinjaTrap::g_Hit_Points() const { return this->Hit_Points;}
const int&			NinjaTrap::g_Hit_Points_Max() const { return this->Hit_Points_Max;}
const int&			NinjaTrap::g_Energy_Points() const { return this->Energy_Points;}
const int&			NinjaTrap::g_Energy_Points_Max() const { return this->Energy_Points_Max;}
const int&			NinjaTrap::g_Level() const { return this->Level;}
const std::string&	NinjaTrap::g_Name() const { return this->Name;}
const size_t&		NinjaTrap::g_DMG_Melee() const { return this->DMG_Melee;}
const size_t&		NinjaTrap::g_DMG_Ranged() const { return this->DMG_Ranged;}
const int&			NinjaTrap::g_DMR_Armor_Re() const { return this->DMR_Armor_Re;}
