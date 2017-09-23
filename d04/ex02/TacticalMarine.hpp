/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TACTICALMARINE__
#define __TACTICALMARINE__

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine(TacticalMarine const & src);
	TacticalMarine&				operator=(TacticalMarine const & rhs);
	TacticalMarine(void);
	~TacticalMarine();
	ISpaceMarine				*clone() const;
	void						battleCry() const;
	void						rangedAttack() const;
	void						meleeAttack() const;
private:
};


#endif