/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_NCURSES.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MGR_GRAPHICS__
#define __MGR_GRAPHICS__
#include "IMonitorDisplay.hpp"
#include <curses.h>
#include <ncurses.h>
#include <mutex>
#include <thread>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#define WORLD_WIDTH				180
#define WORLD_HEIGHT			46
#define DEBUG_DISABLE_NCURSES	0

class	IMonitorDisplay;

class	MGR_NCURSES : public IMonitorDisplay
{
public:
	//Coplein
	~MGR_NCURSES(void);
	static MGR_NCURSES*	getInstance();
	void					Graphics_Start();
	void					Graphics_End();
	int						get_offset_x();
	int						get_map_max_x();
	int						get_offset_y();
	int						get_map_max_y();
	void					Render_Start();
	void					Render_End();
	void					print_message(std::string str);
	void					Render_String_Block(std::vector<std::string> block,
												int x, int y);

private:
	static MGR_NCURSES		*singletonInstance;
	static std::mutex m_;
	MGR_NCURSES(void);
	MGR_NCURSES(MGR_NCURSES const & src);
	MGR_NCURSES &			operator=(MGR_NCURSES const & src);

	// Note: Scott Meyers mentions in his Effective Modern
	//       C++ book, that deleted functions should generally
	//       be public as it results in better error messages
	//       due to the compilers behavior to check accessibility
	//       before deleted status
	WINDOW		*game_window;
	WINDOW		*border_window;
	int			offsetx;
	int			offsety ;
	int			max_y;
	int			max_x;
	int			margin_x;
	int			margin_y;
	bool		graphics_end;
};

#endif