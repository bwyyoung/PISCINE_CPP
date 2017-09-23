/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VICTIM__
#define __VICTIM__

#include <iostream>
#include <string>

class		Victim
{
public:
	Victim(std::string name);
	Victim(Victim const & src);
	virtual ~Victim();
	Victim&	operator=(Victim const & rhs);
	const std::string	get_name() const;
	virtual void	getPolymorphed() const;
protected:
	Victim(void);
	std::string		name;
};

std::ostream& operator<<(std::ostream &o, Victim const & rhs);

#endif