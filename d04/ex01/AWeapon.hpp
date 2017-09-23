/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_WEAPON__
#define __A_WEAPON__

#include <iostream>
#include <string>

class		AWeapon
{
public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const & src);
	virtual ~AWeapon();
	AWeapon&	operator=(AWeapon const & rhs);

	const std::string	get_name() const;
	int					getAPCost() const;
	int					getDamage() const;
	virtual void		attack() const = 0;
protected:
	AWeapon(void);
	std::string			name;
	int					apcost;
	int					damage;
};

#endif