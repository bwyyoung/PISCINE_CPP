/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay() {}

IMonitorDisplay::~IMonitorDisplay() {}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const& rhs)
{
	UNUSED(rhs);
	return ;
}

IMonitorDisplay&			IMonitorDisplay::operator=(IMonitorDisplay const & rhs)
{
	UNUSED(rhs);
	return (*this);
}
