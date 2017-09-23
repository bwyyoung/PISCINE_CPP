/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->init("NO_NAME");
}


ClapTrap::ClapTrap(std::string name)
{
	this->init(name);
	return;
}

void ClapTrap::init(std::string name)
{
	this->Name = name;
	this->Hit_Points = 1000;
	this->Hit_Points_Max = 1000;
	this->Energy_Points = 1000;
	this->Energy_Points_Max = 1000;
	this->Level = 10;
	this->DMG_Melee = 300;
	this->DMG_Ranged = 200;
	this->DMR_Armor_Re = 50;
	std::cout << this->Name << " -- start bootup sequence." << std::endl;
	std::cout << this->Name
			  <<": Booting sequence complete. Hello! I am your new steward bot. "
			  << "Designation: CL4P-TP, Hyperion Robot, Class C."
			  <<"Please adjust factory settings to meet your needs"
			  <<"before deployment." << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	std::cout << "Claptrap: \"Knock-knock.\"\n"
			  << "CloneTrap: \"Who's there?\"\n"
			  << "Claptrap: \"Tat.\"\n"
			  << "CloneTrap: \"Tat who?\" "
			  <<"Claptrap: \"Not until you're older.\"!" << std::endl;
	this->Name = "CloneTrap";
	*this = src;
	return;
}

ClapTrap::~ClapTrap(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	std::cout << this->Name << ": If only my chassis... " <<
			"weren't made of recycled human body parts! Wahahaha!" << std::endl;
	return;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & rhs)
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

void		ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "CL4P-TP "
		<< this->Name
		<< " attacks "
		<<target
		<<" at range, causing "
		<<this->DMG_Ranged
		<<" points of damage !" << std::endl;
}

void		ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "CL4P-TP "
		 << this->Name
		 << " attacks "
		 <<target
		 <<" at melee, causing "
		 <<this->DMG_Melee
		 <<" points of damage !" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	amount = (((int)amount - this->DMR_Armor_Re > 0) ?
			  ((int)amount - this->DMR_Armor_Re) : 0);
	this->Hit_Points = ((int)this->Hit_Points - (int)amount) <= 0 ? 0 :
					   ((int)this->Hit_Points - (int)amount);
	std::cout << "CL4P-TP "
			 << this->Name
			 << " takes "
			 << amount
			 <<" points of damage ! HP:"<< this->Hit_Points << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
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
	std::cout << "CL4P-TP "
		 << this->Name
		 << " takes "
		 << amount
		 <<" points of repair ! HP:"<< this->Hit_Points<< std::endl;
}
