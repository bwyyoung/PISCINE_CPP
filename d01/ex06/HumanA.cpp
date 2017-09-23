/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &theweapon)
{
	this->name = name;
	//theweapon --> point to address of reference, WHICH WILL BE DESTROYED
	// at the end of the function
	//&theweapon --> address of original object
	//http://stackoverflow.com/questions/9263658/how-to-get-a-pointer-from-a-reference
	this->weapon = &theweapon;

	// &&var -->
	// move constructor that take rvalue, and steals theweapon resources
	// rvalue reference overload
	//It's only preferable to store references as data members if they're
	// being assigned at construction,
	// and there is truly no reason to ever change them.
	// Since references cannot be reassigned, they are very limited.
	//this is similar to **root during binary trees
	//*root->item allows you to modify that item, and when the function
	//completes, the change is kept in memory.
	//This moves the temporary object (&&theweapon) into the object being
	//constructed (this->weapon), thereby saving its data inside the class.

	//When we do a club.setType, we are actually setting the club data
	//stored inside this->weapon rather than club itself.

	//therefore doing x = &&var is the same as x = std::move(var),
	//and var is now empty of contents, which are moved to x.
	//http://en.cppreference.com/w/cpp/utility/move
}

HumanA::HumanA(std::string name)
{
	this->name = name;
}

HumanA::~HumanA()
{

}

void HumanA::setWeapon(Weapon &theweapon) // rvalue reference overload with &&
{
	//An lvalue being an expression that refers to a memory location and allows
	//us to take the address of that memory location via the & operator.
	this->weapon = &theweapon;
}

void HumanA::attack()
{
	//effectively we are calling *(weapon)->name;
	std::cout	<< this->name
				<<" attacks with his "<<this->weapon->getType() << std::endl;
}