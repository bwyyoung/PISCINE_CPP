/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Terminal_Keyboard.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_Terminal.hpp"
#include "displays/MGR_QT.hpp"

bool 				MGR_Terminal::keyboard_event(void)
{
	int		ch = getch();
	if (ch != ERR)
	{
		ungetch(ch);
		return true;
	}
	return false;
}

void				MGR_Terminal::get_keyboard_event()
{
	this->key_pressed = -1;
	if (this->keyboard_event())
	{
		this->key_pressed = getch();

		switch (this->key_pressed)
		{
			case APP_KEY_SPACE:
				break;
			case APP_KEY_ESC:
				if (getch() == APP_KEY_SPECIAL)
					switch (getch())
					{
						case APP_KEY_UP:
							break;
						case APP_KEY_DOWN:
							break;
						case APP_KEY_LEFT:
							break;
						case APP_KEY_RIGHT:
							break;
					}
				else
					this->QUIT();
					MGR_QT::getInstance()->QUIT();
				break;
		}
	}
}