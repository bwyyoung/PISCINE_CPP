/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SQUAD__
#define __SQUAD__

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class		Squad : public ISquad
{
public:
	Squad(Squad const & src);
	Squad&				operator=(Squad const & rhs);
	Squad(void);
	~Squad();
	int					getCount() const;
	ISpaceMarine*		getUnit(int) const;
	int					push(ISpaceMarine*);
private:
	void				destroy_container();
	bool				check_unit_inside(ISpaceMarine*);
	typedef struct		s_marines
	{
		s_marines		*next;
		ISpaceMarine	*ptr;
	}					t_marines;
	t_marines			*container;
};

#endif