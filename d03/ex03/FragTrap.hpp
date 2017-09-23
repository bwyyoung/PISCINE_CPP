/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef __FRAGTRAP__
#define __FRAGTRAP__

#define NRG_VATS 25

class FragTrap : public ClapTrap
{
private:
	FragTrap(void);
public:
	void		init(std::string name);
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap&	operator=(FragTrap const & rhs);
	void		vaulthunter_dot_exe(std::string const & target);
private:
	static const char* const	attacks[5];
	void		(FragTrap::*attack_ptr[2])(std::string const & target);
};

#endif