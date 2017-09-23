/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SORCERER__
#define __SORCERER__

#include "Victim.hpp"
#include <iostream>
#include <string>

class		Sorcerer
{
	public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const & src);
	virtual ~Sorcerer();
	Sorcerer&	operator=(Sorcerer const & rhs);
	const std::string	get_name_title() const;
	const std::string	get_name() const;
	const std::string	get_title() const;
	void		polymorph(Victim const &) const;
	private:
	Sorcerer(void);
	std::string		name;
	std::string		title;
};

std::ostream& operator<<(std::ostream &o, Sorcerer const & rhs);

#endif