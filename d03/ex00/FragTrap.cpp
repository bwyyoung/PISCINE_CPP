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

FragTrap::FragTrap(void)
{
	this->init("NO_NAME");
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
			  "Obey Jack at all costs. Directive three: Dance!" << std::endl;
	attack_ptr[0] = &FragTrap::rangedAttack;
	attack_ptr[1] = &FragTrap::meleeAttack;
}

FragTrap::FragTrap(std::string name)
{
	this->init(name);
	return;
}

FragTrap::FragTrap(FragTrap const & src)
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
	std::cout << this->Name << ": If only my chassis... " <<
			"weren't made of recycled human body parts! Wahahaha!" << std::endl;
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
	this->Name = rhs.Name;
	this->Hit_Points = rhs.Hit_Points;
	this->Hit_Points_Max = rhs.Hit_Points_Max;
	this->Energy_Points = rhs.Energy_Points;
	this->Energy_Points_Max = rhs.Energy_Points_Max;
	this->Level = rhs.Level;
	this->DMG_Melee = rhs.DMG_Melee;
	this->DMG_Ranged = rhs.DMG_Ranged;
	this->DMR_Armor_Re = rhs.DMR_Armor_Re;
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

void		FragTrap::takeDamage(unsigned int amount)
{
	amount = (((int)amount - this->DMR_Armor_Re > 0) ?
			  ((int)amount - this->DMR_Armor_Re) : 0);
	this->Hit_Points = ((int)this->Hit_Points - (int)amount) <= 0 ? 0 :
					   ((int)this->Hit_Points - (int)amount);
	std::cout << "FR4G-TP "
			 << this->Name
			 << " takes "
			 << amount
			 <<" points of damage ! HP:"<< this->Hit_Points << std::endl;

}

void		FragTrap::beRepaired(unsigned int amount)
{
	int		repair_final = this->Hit_Points + (int)amount - this->Hit_Points_Max;
	if (repair_final > 0)
		amount = repair_final;
	this->Hit_Points += amount;
	if (this->Hit_Points > this->Hit_Points_Max)
	{
		amount -= (this->Hit_Points - this->Hit_Points_Max);
		this->Hit_Points = this->Hit_Points_Max;
	}
	std::cout << "FR4G-TP "
		 << this->Name
		 << " takes "
		 << amount
		 <<" points of repair ! HP:"<< this->Hit_Points<< std::endl;
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
