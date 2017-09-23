/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Terminal_Render.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_Terminal.hpp"

void			MGR_Terminal::display_app()
{
	MGR_NCURSES::getInstance()->Render_Start();
	MGR_Module::getInstance()->Render_Terminal();
	MGR_Module::getInstance()->Render_QT();
	MGR_NCURSES::getInstance()->Render_End();
}