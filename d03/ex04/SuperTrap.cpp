/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) : ClapTrap("NO_NAME"), FragTrap("NO_NAME"), NinjaTrap("NO_NAME")
{
	this->init("NO_NAME");
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	this->init(name);
	return;
}

void SuperTrap::init(std::string name)
{
	this->Name = name;
	this->Level = 1;

	FragTrap::Energy_Points = NinjaTrap::Energy_Points;
	FragTrap::Energy_Points_Max = NinjaTrap::Energy_Points_Max;

	std::cout << this->Name << " -- start bootup sequence." << std::endl;
	std::cout << this->Name
			  <<": Booting sequence complete. Hello! I am your new steward bot. "
			  << "Designation: SUPER-TP, Hyperion Robot, Class C."
			  <<"Please adjust factory settings to meet your needs"
			  <<"before deployment." << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const & src) : ClapTrap(src), FragTrap(src), NinjaTrap(src)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	std::cout << "SuperTrap: \"Knock-knock.\"\n"
			  << "CloneTrap: \"Who's there?\"\n"
			  << "SuperTrap: \"Tat.\"\n"
			  << "CloneTrap: \"Tat who?\" "
			  <<"SuperTrap: \"Not until you're older.\"!" << std::endl;
	this->Name = "CloneTrap";
	*this = src;
	return;
}

SuperTrap::~SuperTrap(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	std::cout << this->Name << ": Oh. My. God. What if I'm like... a fish? And, "
	<< "if I'm not moving... I stop breathing? AND THEN I'LL DIE! HELP ME! HELP"
	<< " MEEEEE HEE HEE HEEE! HHHHHHHELP!" << std::endl;
	return;
}

SuperTrap&	SuperTrap::operator=(SuperTrap const & rhs)
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
	FragTrap::Hit_Points = rhs.g_Hit_Points();
	FragTrap::Hit_Points_Max = rhs.g_Hit_Points_Max();
	this->Level = rhs.g_Level();
	NinjaTrap::DMG_Melee = rhs.g_DMG_Melee();
	FragTrap::DMG_Ranged = rhs.g_DMG_Ranged();
	FragTrap::DMR_Armor_Re = rhs.g_DMR_Armor_Re();

	NinjaTrap::Energy_Points = rhs.g_Energy_Points();
	NinjaTrap::Energy_Points_Max = rhs.g_Energy_Points_Max();
	FragTrap::Energy_Points = NinjaTrap::Energy_Points;
	FragTrap::Energy_Points_Max = NinjaTrap::Energy_Points_Max;
	return *this;
}

void		SuperTrap::vaulthunter_dot_exe(std::string const & target)
{
	FragTrap::vaulthunter_dot_exe(target);
	NinjaTrap::Energy_Points = FragTrap::g_Energy_Points();
}

void		SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}

void		SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::meleeAttack(target);
}

void		SuperTrap::takeDamage(unsigned int amount)
{
	FragTrap::takeDamage(amount);
}

void		SuperTrap::beRepaired(unsigned int amount)
{
	FragTrap::beRepaired(amount);
}

const int&			SuperTrap::g_Hit_Points() const { return FragTrap::Hit_Points;}
const int&			SuperTrap::g_Hit_Points_Max() const { return FragTrap::Hit_Points_Max;}
const int&			SuperTrap::g_Level() const { return this->Level;}
const std::string&	SuperTrap::g_Name() const { return this->Name;}
const size_t&		SuperTrap::g_DMG_Melee() const { return NinjaTrap::DMG_Melee;}
const size_t&		SuperTrap::g_DMG_Ranged() const { return FragTrap::DMG_Ranged;}
const int&			SuperTrap::g_DMR_Armor_Re() const { return FragTrap::DMR_Armor_Re;}
const int&			SuperTrap::g_Energy_Points() const { return NinjaTrap::Energy_Points;}
const int&			SuperTrap::g_Energy_Points_Max() const { return NinjaTrap::Energy_Points_Max;}