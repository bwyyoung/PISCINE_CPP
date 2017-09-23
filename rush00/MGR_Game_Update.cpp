/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Game_Update.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_Game.hpp"

void				MGR_Game::update_game()
{
	this->update_game_top_down();
	this->update_game_bottom_up();
	this->update_spawn();
}

void				MGR_Game::update_stars()
{
	int			i = -1;
	int			x;
	int			y;
	//Now update the stars that were hidden behind enemies or players.
	while (++i < NUM_STARS)
	{
		x = this->CONTAINER_STAR[i].getX();
		y = this->CONTAINER_STAR[i].getY();
		if (!this->CONTAINER_STAR[i].isActive())
			continue;
		//Star is already visible in map.. its ok
		if (this->map_grid[x][y] == &this->CONTAINER_STAR[i])
			continue;
		//For stars that are not visible, we update them.
		this->CONTAINER_STAR[i].update();
		this->Update_Entity_Grid(&(this->CONTAINER_STAR[i]));
	}
}

void				MGR_Game::update_powerup()
{
	int			i = -1;
	Powerup		*current;
	IEntity		*onleft;
	IEntity		*onright;
	int			x;
	int			y;
	//Now update the powerup to move sideways
	while (++i < NUM_POWERUPS)
	{
		current = &this->CONTAINER_POWERUP[i];
		x = current->getX();
		y = current->getY();
		if (!current->isActive())
			continue;
		if (current->moving_left())
		{
			if (x - 1 <= 0)
			{
				current->flip_direction();
				continue;
			}
			onleft = this->map_grid[x - 1][y];
			if ((onleft != NULL) && (onleft->getType() != ENTITY_STAR)
				&& (onleft->getType() != ENTITY_PLAYER))
			{
				current->flip_direction();
				continue;
			}
		}
		else
		{
			if (x + 1 >= WORLD_WIDTH)
			{
				current->flip_direction();
				continue;
			}
			onright = this->map_grid[x + 1][y];
			if ((onright != NULL)
				&& (onright->getType() != ENTITY_STAR)
				&& (onright->getType() != ENTITY_PLAYER))
			{
				current->flip_direction();
				continue;
			}
		}
		this->Remove_Entity_Grid(current);
		current->move_sideways();
		this->Update_Entity_Grid(&(this->CONTAINER_POWERUP[i]));
	}
}

void				MGR_Game::update_game_bottom_up()
{
	IEntity		*current;

	for (int y = WORLD_HEIGHT - 1; y >= 0; y--)
		for (int x = 0; x < WORLD_WIDTH; x++)
		{
			if (this->map_grid[x][y] == NULL)
				continue;
			current = this->map_grid[x][y];
			if ((current->getType() != ENTITY_STAR) &&
				(current->getType() != ENTITY_ENEMY)&&
				(current->getType() != ENTITY_POWERUP))
				continue;
			this->Remove_Entity_Grid(current);
			current->update();
			this->Update_Entity_Grid(current);
		}
	this->update_powerup();
	this->update_stars();
}

void				MGR_Game::update_game_top_down()
{
	IEntity		*current;
	for (int y = 0; y < WORLD_HEIGHT; y++)
		for (int x = 0; x < WORLD_WIDTH; x++)
		{
			if (this->map_grid[x][y] == NULL)
				continue;
			current = this->map_grid[x][y];
			if (current->getType() != ENTITY_BULLET)
				continue;
			this->Remove_Entity_Grid(current);
			current->update();
			this->Update_Entity_Grid(current);
		}
}

void				MGR_Game::update_spawn()
{
	if (!DEBUG_DISABLE_ENEMY)
		if (get_num_active_enemy() < MIN_NUM_ENEMIES)
		{
			int		i = -1;
			while (++i < ENEMY_SPAWN_RATE)
			{
				Enemy	*new_enemy = this->spawn_enemy();
				if (!new_enemy)
					break;
				setup_spawn(new_enemy);
			}
		}
	if (get_num_active_star() < NUM_STARS)
	{
		int		i = -1;
		while (++i < STAR_SPAWN_RATE)
		{
			Star	*new_star = this->spawn_star();
			if (!new_star)
				break;
			setup_spawn(new_star);
		}
	}

	if (get_num_active_powerup() < NUM_POWERUPS)
	{
		int		i = -1;
		while (++i < NUM_POWERUPS)
		{
			Powerup	*new_powerup = this->spawn_powerup();
			if (!new_powerup)
				break;
			setup_spawn(new_powerup);
		}
	}
	if (user.isActive())
		return ;
	user.activate(WORLD_WIDTH / 2, WORLD_HEIGHT - 1);
	this->Update_Entity_Grid(&user);
}
