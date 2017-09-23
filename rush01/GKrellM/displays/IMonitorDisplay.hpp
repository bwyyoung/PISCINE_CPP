/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PISCINE_C_IMONITORDISPLAY_HPP
#define PISCINE_C_IMONITORDISPLAY_HPP

# define UNUSED(x)				static_cast<void>(x)

#include <vector>
#include <string>

class		IMonitorDisplay
{
public:
	IMonitorDisplay();
	virtual ~IMonitorDisplay();
private:
	IMonitorDisplay(IMonitorDisplay const &src);
	IMonitorDisplay				&operator=(IMonitorDisplay const &rhs);
	virtual void				Render_String_Block(std::vector<std::string> block,
												int x, int y) = 0;
};

#endif
