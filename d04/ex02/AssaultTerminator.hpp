/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ASSAULTTERMINATOR__
#define __ASSAULTTERMINATOR__

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator(AssaultTerminator const & src);
	AssaultTerminator&				operator=(AssaultTerminator const & rhs);
	AssaultTerminator(void);
	~AssaultTerminator();
	ISpaceMarine				*clone() const;
	void						battleCry() const;
	void						rangedAttack() const;
	void						meleeAttack() const;
private:
};


#endif