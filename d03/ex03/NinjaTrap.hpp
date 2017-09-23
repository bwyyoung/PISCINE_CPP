/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef __NINJATRAP__
#define __NINJATRAP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
private:
	NinjaTrap(void);
public:
	void		init(std::string name);
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap(void);
	NinjaTrap&	operator=(NinjaTrap const & rhs);
	void		ninjaShoebox(NinjaTrap & rhs);
	void		ninjaShoebox(ClapTrap & rhs);
	void		ninjaShoebox(FragTrap & rhs);
	void		ninjaShoebox(ScavTrap & rhs);
private:

};

#endif