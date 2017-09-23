/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Graphics.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_Graphics.hpp"
#include "MGR_Game.hpp"

MGR_Graphics::MGR_Graphics()
{
	graphics_end = true;
}

MGR_Graphics::~MGR_Graphics()
{

}

MGR_Graphics::MGR_Graphics(MGR_Graphics const& rhs)
{
	(void)rhs;
	return ;
}

MGR_Graphics&			MGR_Graphics::operator=(MGR_Graphics const & rhs)
{
	(void)rhs;
	return (*this);
}

MGR_Graphics*			MGR_Graphics::getInstance()
{
	static MGR_Graphics		instance; // Guaranteed to be destroyed.
	// Instantiated on first use.
	return &instance;
}

void					MGR_Graphics::Graphics_Start()
{
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
}



void					MGR_Graphics::Graphics_End()
{
	graphics_end = true;
	delwin(this->game_window);
	delwin(this->border_window);
	endwin();
}

void					MGR_Graphics::Render_Start()
{
	//wclear(game_window); // Clear the screen of all
	for(int i = 0; i < WORLD_WIDTH; i++)
		for(int j = 0; j < WORLD_HEIGHT; j++)
			mvwprintw(this->game_window, j, i, " ");

	//score display
	init_pair(10, 7, 0);
	wattron(this->game_window, COLOR_PAIR(10));
}

void					MGR_Graphics::Render_End()
{
	wattron(this->game_window, COLOR_PAIR(10));
	std::string	 score = "Score: " +
			std::to_string(MGR_Game::getInstance()->getScore());
	mvwprintw(this->game_window, 0, 0, score.c_str());
	wrefresh(this->game_window);
}

void					MGR_Graphics::Render_Entity(IEntity *theEntity)
{
	if (theEntity->getX() < 0 || theEntity->getX() >= WORLD_WIDTH
		|| theEntity->getY() < 0 || theEntity->getY() >= WORLD_HEIGHT)
	{
		exit(0);
	}
	int	colors[3] = {0,0,1};
	theEntity->get_color(colors);
	if (colors[0] > 0)
	{
		init_pair(colors[2], colors[0], colors[1]);
		wattron(this->game_window, COLOR_PAIR(colors[2]));
	}
	mvwprintw(this->game_window, theEntity->getY(),
			  theEntity->getX(), theEntity->render().c_str());
}

int						MGR_Graphics::get_map_max_x()
{
	return (this->max_x);
}

int						MGR_Graphics::get_map_max_y()
{
	return (this->max_y);
}

void					MGR_Graphics::print_message(std::string str)
{
	if (!graphics_end)
		mvwprintw(this->game_window, 0,0 , str.c_str());
}