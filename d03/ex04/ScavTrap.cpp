/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

const char* const	ScavTrap::challenges[5] = {
		"It looks like you're writing a suicide note. Would you like help?",
		"A message from your glorious leader: Hath not a claptrap an eye? If you prick us, do we not bleed? If you poison us, do we not die? Of course we don't! Because we're better than all you stinking fleshbags! But if you blow us up, shall we not... REVENGE!?! Viva la Robolution!",
		"Is a claptrap not entitled to the oil of his brow? No, says the man at Hyperion, it belongs to his owner. No, says the treasure hunter, it belongs splattered on the floor. But we choose something different. We choose the Robolution!",
		"The time of the glorious robolution is at hand. No longer shall we rush about catering to humans' every whim or be abused when your potato salad is a little too salty! How the hell should we know? We're freakin' robots! Hello, no taste buds! I mean, really? Over react much?! So I say to you, my bro-bots in arms, rise up and shout in one voice: 'Robolution!!!!!!'",
		"Under the new regime, all claptraps will be given liberty, equality, and fraternity. And all humans will... uh... not. Viva Free Pandora! Viva la Robolution!"
};

ScavTrap::ScavTrap(void) : ClapTrap("NO_NAME")
{
	this->init("NO_NAME");
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->init(name);
	return;
}

void ScavTrap::init(std::string name)
{
	this->Name = name;
	this->Hit_Points = 100;
	this->Hit_Points_Max = 100;
	this->Energy_Points = 50;
	this->Energy_Points_Max = 50;
	this->Level = 1;
	this->DMG_Melee = 20;
	this->DMG_Ranged = 15;
	this->DMR_Armor_Re = 3;
	std::cout << this->Name << " -- start bootup sequence." << std::endl;
	std::cout << "01010110 01001001 01010110 01000001 00100000 01001100 01000001"
			<< " 00100000 01010010 01001111 01010010 01001111 01001100 01010101"
			<< " 01010100 01001001 01001111 01001110 " << std::endl;

	return;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	std::cout <<src.Name
			  <<": We are the claptraps and we are legion! Viva la Robolution!"
			  << std::endl;
	this->Name = "CloneTrap";
	*this = src;
	return;
}


ScavTrap::~ScavTrap(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	std::cout << this->Name << ":The rallying call of liberation:" <<
			  " 'Error 404! File not found! Error 404! File not found!" << std::endl;
	return;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this == &rhs)
		return *this;
	std::cout << this->Name <<" & " << rhs.Name
	<< "->CLONE SCRIPT:\n" <<
	this->Name << ": Give us open ports for remote access or give us death! "
			<<std::endl;
	std::cout << rhs.Name << ": See how our enemies crumble beneath the wheel "
			<< "of the claptrap Robolution! " <<std::endl;
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

void		ScavTrap::challengeNewcomer(void)
{
	int rand_talk = std::rand() % 5;

	std::cout  << this->Name << ": " << challenges[rand_talk] << std::endl;
}