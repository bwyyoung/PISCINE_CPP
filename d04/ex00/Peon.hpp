/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PEON__
#define __PEON__

#include "Victim.hpp"

class		Peon : public Victim
{
public:
	Peon(std::string name);
	Peon(Peon const & src);
	~Peon();
	Peon&	operator=(Peon const & rhs);
	const std::string	get_name() const;
	void	getPolymorphed() const;
private:
	Peon(void);
	std::string		name;
	std::string		title;
};

std::ostream& operator<<(std::ostream &o, Peon const & rhs);

#endif