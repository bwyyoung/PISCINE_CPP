/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER__
#define __CHARACTER__

#include "AWeapon.hpp"
#include "Enemy.hpp"

#define AP_LIMIT 40

class		Character
{
public:
	Character(std::string const & name);
	Character(Character const & src);
	~Character();
	Character&	operator=(Character const & rhs);
	void	recoverAP();
	void	equip(AWeapon*);
	void	attack(Enemy*);
	std::string const	getName() const;
	int				getAP() const;
	std::string const	getWeapon_Name() const;
	bool				has_weapon()const;
private:
	Character(void);
	std::string		name;
	int				ap;
	AWeapon			*weapon;
};

std::ostream& operator<<(std::ostream &o, Character const & rhs);


#endif