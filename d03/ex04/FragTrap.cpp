/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

const char* const	FragTrap::attacks[5] = {
		"Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew!",
		"Boiyoiyoiyoiyoing!",
		"Gotta blow up a bad guy, GOTTA BLOW UP A BAD GUY!",
		"Kill, reload! Kill, reload! KILL! RELOAD!",
		"Is it dead? Can, can I open my eyes now?"
};

FragTrap::FragTrap(void) : ClapTrap("NO_NAME")
{
	this->init("NO_NAME");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->init(name);
	return;
}

void FragTrap::init(std::string name)
{
	this->Name = name;
	this->Hit_Points = 100;
	this->Hit_Points_Max = 100;
	this->Energy_Points = 100;
	this->Energy_Points_Max = 100;
	this->Level = 1;
	this->DMG_Melee = 30;
	this->DMG_Ranged = 20;
	this->DMR_Armor_Re = 5;
	std::cout << this->Name << " -- start bootup sequence." << std::endl;
	std::cout << "Directive one: Protect humanity! Directive two: " <<
			"Obey Jack at all costs. Directive three: Frag!" << std::endl;
	attack_ptr[0] = &FragTrap::rangedAttack;
	attack_ptr[1] = &FragTrap::meleeAttack;
	return;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	std::cout << src.Name
			<<": I can do more than open doors sir! We FR4G-TP units can be "
			<<"programmed to do anything from open doors to frag-sassinate "
			<<"highly important Janitory officials!" << std::endl;
	this->Name = "CloneTrap";
	*this = src;
	return;
}

FragTrap::~FragTrap(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	std::cout << this->Name << ": You. Are. Not. Dead! Your new designation is "
	<< "FR4G-TP. Fragtrap. You are a merciless killing machine. Got it?"
  	<< std::endl;
	return;
}

FragTrap&	FragTrap::operator=(FragTrap const & rhs)
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

	std::cout << rhs.g_Hit_Points() << std::endl;
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

void		FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP "
			  << this->Name
			  << " attacks "
			  <<target
			  <<" at range, causing "
			  <<this->DMG_Ranged
			  <<" points of damage !" << std::endl;
}

void		FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP "
			  << this->Name
			  << " attacks "
			  <<target
			  <<" at melee, causing "
			  <<this->DMG_Melee
			  <<" points of damage !" << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int		values[8] = { 0, 1, 0, 0, 1, 1, 1, 1};
	int		rand_talk = std::rand() % 5;
	int		rand_attack = std::rand() % 8;

	if (((int)this->Energy_Points - NRG_VATS) < 0)
	{
		std::cout << "Where'd all my bullets go? NRG:"
				  << this->Energy_Points<< std::endl;
		return ;
	}
	std::cout << this->Name << ":Activating VaultHunter.EXE: "
			  << "Look out everybody, things are about to get awesome!"
			  << std::endl;
	this->Energy_Points -= NRG_VATS;
	(this->*attack_ptr[values[rand_attack]])(target);
	std::cout << this->Name << ": " <<attacks[rand_talk] << std::endl;
	(void)target;
}

void		FragTrap::takeDamage(unsigned int amount)
{
	this->Hit_Points = calc_dmg(amount, this->DMR_Armor_Re, this->Hit_Points);
	std::cout << "FR4G-TP "
			  << this->Name
			  << " takes "
			  << amount
			  <<" points of damage ! HP:"<< this->Hit_Points << std::endl;
}

void		FragTrap::beRepaired(unsigned int amount)
{
	this->Hit_Points = calc_repair(amount,
								   this->Hit_Points_Max, this->Hit_Points);
	std::cout << "FR4G-TP "
			  << this->Name
			  << " takes "
			  << amount
			  <<" points of repair ! HP:"<< this->Hit_Points<< std::endl;
}

const int&			FragTrap::g_Hit_Points() const { return this->Hit_Points;}
const int&			FragTrap::g_Hit_Points_Max() const { return this->Hit_Points_Max;}
const int&			FragTrap::g_Energy_Points() const { return this->Energy_Points;}
const int&			FragTrap::g_Energy_Points_Max() const { return this->Energy_Points_Max;}
const int&			FragTrap::g_Level() const { return this->Level;}
const std::string&	FragTrap::g_Name() const { return this->Name;}
const size_t&		FragTrap::g_DMG_Melee() const { return this->DMG_Melee;}
const size_t&		FragTrap::g_DMG_Ranged() const { return this->DMG_Ranged;}
const int&			FragTrap::g_DMR_Armor_Re() const { return this->DMR_Armor_Re;}