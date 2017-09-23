/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POWERFIST__
#define __POWERFIST__

#include "AWeapon.hpp"

class		PowerFist : public AWeapon
{
public:
	PowerFist(void);
	PowerFist(PowerFist const & src);
	~PowerFist();
	PowerFist&	operator=(PowerFist const & rhs);
	void				attack() const;
protected:
};

#endif