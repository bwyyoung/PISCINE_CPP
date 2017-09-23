/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_NCURSES.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_NCURSES.hpp"

#define GREEN_PAIR 1
#define YELLOW__PAIR 2

MGR_NCURSES*			MGR_NCURSES::singletonInstance = nullptr;
std::mutex				MGR_NCURSES::m_;

MGR_NCURSES::MGR_NCURSES()
{
	graphics_end = true;

}

MGR_NCURSES::~MGR_NCURSES()
{

}

MGR_NCURSES::MGR_NCURSES(MGR_NCURSES const& rhs)
{
	(void)rhs;
	return ;
}

MGR_NCURSES&			MGR_NCURSES::operator=(MGR_NCURSES const & rhs)
{
	(void)rhs;
	return (*this);
}

MGR_NCURSES*			MGR_NCURSES::getInstance()
{
	std::lock_guard<std::mutex> lock(m_);
	if(singletonInstance == nullptr)
		singletonInstance = new MGR_NCURSES();
	return singletonInstance;
}

void					MGR_NCURSES::Graphics_Start()
{
	if (DEBUG_DISABLE_NCURSES)
		return;
	margin_x = 2;
	margin_y = 2;
	graphics_end = false;
	initscr();
	noecho();
	refresh();
	curs_set(FALSE); // Don't display a cursor
	this->offsetx = (COLS - WORLD_WIDTH) / 2;
	this->offsety = (LINES - WORLD_HEIGHT) / 2;
	this->border_window = newwin(WORLD_HEIGHT + 2, WORLD_WIDTH + 2,
								offsety - 1, offsetx - 1);
	this->game_window = newwin(WORLD_HEIGHT, WORLD_WIDTH, offsety, offsetx);
	// Global var `stdscr` is created by the call to `initscr()`
	getmaxyx(stdscr, this->max_y, this->max_x);
	cbreak();
	nodelay(stdscr, TRUE);
	start_color();
	box(border_window, 0 , 0); //setup borders to our game..
	wrefresh(this->border_window);
	short		line_colors[3] = {COLOR_GREEN,0,GREEN_PAIR};
	short		title_colors[3] = {COLOR_YELLOW,0,YELLOW__PAIR};
	init_pair(title_colors[2], title_colors[0], title_colors[1]);
	init_pair(line_colors[2], line_colors[0], line_colors[1]);
	init_pair(10, 7, 0);
	wattron(this->game_window, COLOR_PAIR(10));
}

void					MGR_NCURSES::Graphics_End()
{
	if (DEBUG_DISABLE_NCURSES)
		return;
	graphics_end = true;
	delwin(this->game_window);
	delwin(this->border_window);
	endwin();
}

void					MGR_NCURSES::Render_Start()
{
	if (DEBUG_DISABLE_NCURSES)
		return;
	for(int i = 0; i < WORLD_WIDTH; i++)
		for(int j = 0; j < WORLD_HEIGHT; j++)
			mvwprintw(this->game_window, j, i, " ");
	wattron(this->game_window, COLOR_PAIR(10));
}

void					MGR_NCURSES::Render_End()
{
	if (DEBUG_DISABLE_NCURSES)
		return;
	wattron(this->game_window, COLOR_PAIR(10));
	wrefresh(this->game_window);
}

void					MGR_NCURSES::Render_String_Block
								(std::vector<std::string> block, int x, int y)
{
	int			i = 0;

	for (std::vector<std::string>::iterator it = block.begin();
		 it != block.end(); ++it)
	{
		if (!DEBUG_DISABLE_NCURSES && (it != block.end()) && !(*it).empty())
		{
			if (i == 0)
				wattron(this->game_window, COLOR_PAIR(GREEN_PAIR));
			else if (i == 1)
				wattron(this->game_window, COLOR_PAIR(YELLOW__PAIR));
			mvwprintw(this->game_window, y, x, (*it).c_str());
			if (i == 0)
				wattroff(this->game_window, COLOR_PAIR(GREEN_PAIR));
			else if (i == 1)
				wattroff(this->game_window, COLOR_PAIR(YELLOW__PAIR));
			i++;
		}
		y++;
	}
}

int						MGR_NCURSES::get_map_max_x()
{
	return (this->max_x);
}

int						MGR_NCURSES::get_map_max_y()
{
	return (this->max_y);
}

int						MGR_NCURSES::get_offset_x()
{
	return (this->offsetx);
}

int						MGR_NCURSES::get_offset_y()
{
	return (this->offsety);
}

void					MGR_NCURSES::print_message(std::string str)
{
	if (DEBUG_DISABLE_NCURSES)
		return;
	if (!graphics_end)
		mvwprintw(this->game_window, 0,0 , str.c_str());
}