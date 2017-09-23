/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Game.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_Game.hpp"

void				MGR_Game::player_power_up()
{
	user.POWER_UP();
}

void				MGR_Game::display_game()
{
	MGR_Graphics::getInstance()->Render_Start();

	for (int x = 0; x < WORLD_WIDTH; x++)
		for (int y = 0; y < WORLD_HEIGHT; y++)
		{
			if (this->map_grid[x][y] == NULL)
				continue;
			MGR_Graphics::getInstance()->Render_Entity(this->map_grid[x][y]);
			//if (this->map_grid[x][y])
		}
	if (user.powered_up())
	{
		user.move(PLAYER_MOVE_LEFT);
		MGR_Graphics::getInstance()->Render_Entity(&user);
		user.move(PLAYER_MOVE_RIGHT);
		user.move(PLAYER_MOVE_RIGHT);
		MGR_Graphics::getInstance()->Render_Entity(&user);
		user.move(PLAYER_MOVE_LEFT);
	}
	MGR_Graphics::getInstance()->Render_End();
}

void				MGR_Game::Remove_Entity_Grid(IEntity *entity)
{
	int		x =  entity->getX();
	int		y =  entity->getY();
	this->map_grid[x][y] = NULL;
}

void				MGR_Game::Update_Entity_Grid(IEntity *entity)
{
	if (!entity)
		return ;
	int x = entity->getX();
	int y = entity->getY();
	if (entity->getType() == ENTITY_BULLET &&
		this->map_grid[x][y] != NULL)
		if (this->map_grid[x][y]->getType() == ENTITY_BULLET)
		{
			entity->deactivate();
			return;
		}
	if (x < 0 || x >= WORLD_WIDTH || y < 0 || y >= WORLD_HEIGHT)
	{
		entity->deactivate();
		return;
	}

	if (this->map_grid[x][y] == NULL ||
		this->map_grid[x][y]->getType() == ENTITY_STAR)
	{
		this->map_grid[x][y] = NULL;
		this->map_grid[x][y] = entity; //overwrite null or stars on the map with
	}
	//other entities. stars cannot overwrite each other because
	if (this->map_grid[x][y] == NULL &&
		entity->getType() == ENTITY_STAR)
		this->map_grid[x][y] = entity;
	else
	{
		if (entity->getType() == ENTITY_STAR && this->map_grid[x][y] != NULL)
			return ;
		//collision detection
		entity->collideAction(this->map_grid[x][y]);
		//if grid item is deactivated, remove it.
		if (!this->map_grid[x][y]->isActive())
			this->map_grid[x][y] = NULL;
		//if the param entity is still alive, pls put it inside this grid.
		if (entity->isActive())
			this->map_grid[x][y] = entity;
	}
}

void				MGR_Game::LOOP()
{
	DWORD			start_time = GetTickCount();
	DWORD			next_game_tick = start_time;
	DWORD			current;
	DWORD			elapsed;
	int				sleep_time = 0;
	std::srand (time(NULL));
	this->init_game();
	MGR_Graphics::getInstance()->Graphics_Start();
	this->game_is_running = true;

	DWORD			seconds = 0;
	while(game_is_running)
	{
		current = GetTickCount();
		elapsed = current - start_time;
		seconds += elapsed;
		//Get User Input Based on Event received
		get_keyboard_event(); // frame based
		if (seconds > GAME_REFRESH_RATE) //counting 1 second
		{
			//clock based
			seconds = 0;
			update_game();
		}
		display_game();
		next_game_tick += SKIP_TICKS;
		sleep_time = next_game_tick - GetTickCount();
		if( sleep_time >= 0 )
		{
			std::chrono::milliseconds timespan(sleep_time); // or whatever
			std::this_thread::sleep_for(timespan);
		}
		start_time = current;
	}

	MGR_Graphics::getInstance()->Graphics_End();
}

void				MGR_Game::init_game()
{
	score = 0;
	std::memset(this->map_grid, 0, sizeof(this->map_grid));
	user.activate(WORLD_WIDTH / 2, WORLD_HEIGHT - 1);
	this->Update_Entity_Grid(&user);
	is_render = false;
	this->update_spawn();
}
