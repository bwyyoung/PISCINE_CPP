/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Game_Util.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_Game.hpp"


void			MGR_Game::increaseScore(int amount)
{
	this->score += amount;
	if (this->score < 0)
		this->score = 0;
}

int 			MGR_Game::getScore()
{
	return this->score;
}

IEntity				*MGR_Game::get_entity_grid(int x, int y)
{
	return this->map_grid[x][y];
}

void				MGR_Game::get_keyboard_event()
{
	this->key_pressed = -1;
	if (this->keyboard_event())
	{
		this->key_pressed = getch();
		this->Remove_Entity_Grid(&user);
		if (user.powered_up())
		{
			user.move(PLAYER_MOVE_LEFT);
			this->Remove_Entity_Grid(&user);
			user.move(PLAYER_MOVE_RIGHT);
			user.move(PLAYER_MOVE_RIGHT);
			this->Remove_Entity_Grid(&user);
			user.move(PLAYER_MOVE_LEFT);
		}
		switch (this->key_pressed)
		{
			case GAME_KEY_SPACE:
				this->Update_Entity_Grid(user.shoot());
				if (user.powered_up())
				{
					user.move(PLAYER_MOVE_LEFT);
					this->Update_Entity_Grid(user.shoot());
					user.move(PLAYER_MOVE_RIGHT);
					user.move(PLAYER_MOVE_RIGHT);
					this->Update_Entity_Grid(user.shoot());
					user.move(PLAYER_MOVE_LEFT);
				}
				break;
			case GAME_KEY_ESC:
				if (getch() == GAME_KEY_SPECIAL)
					switch (getch())
					{
						case GAME_KEY_UP:
							user.move(PLAYER_MOVE_UP);
							break;
						case GAME_KEY_DOWN:
							user.move(PLAYER_MOVE_DOWN);
							break;
						case GAME_KEY_LEFT:
							user.move(PLAYER_MOVE_LEFT);
							break;
						case GAME_KEY_RIGHT:
							user.move(PLAYER_MOVE_RIGHT);
							break;
					}
				else
					this->game_is_running = false;
				break;
		}
		this->Update_Entity_Grid(&user);
		if (user.powered_up())
		{
			user.move(PLAYER_MOVE_LEFT);
			this->Update_Entity_Grid(&user);
			user.move(PLAYER_MOVE_RIGHT);
			user.move(PLAYER_MOVE_RIGHT);
			this->Update_Entity_Grid(&user);
			user.move(PLAYER_MOVE_LEFT);
		}
	}
}

bool 				MGR_Game::keyboard_event(void)
{
	int		ch = getch();
	if (ch != ERR)
	{
		ungetch(ch);
		return true;
	}
	return false;
}

DWORD				MGR_Game::GetTickCount()
{
	// GetTickCount() returns the current number of milliseconds
	// that have elapsed since the system was started
	struct timespec		ts;
	DWORD				theTick = 0U;
	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts.tv_sec = mts.tv_sec;
	ts.tv_nsec = mts.tv_nsec;
	theTick  = ts.tv_nsec / 1000000;
	theTick += ts.tv_sec * 1000;
	return theTick;
}

void				MGR_Game::setup_spawn(IEntity *entity)
{
	while (true)
	{
		int		x_pos = std::rand() % WORLD_WIDTH;
		if (this->map_grid[x_pos][0] == NULL)
		{
			entity->activate(x_pos, 0);
			this->map_grid[entity->getX()][entity->getY()] = entity;
			break;
		}
	}
}

Enemy				*MGR_Game::spawn_enemy()
{
	int		i = -1;
	while (++i < NUM_ENEMIES)
	{
		if (!(this->CONTAINER_ENEMY[i].isActive()))
			return (&(this->CONTAINER_ENEMY[i]));
	}
	return NULL;
}

Bullet				*MGR_Game::spawn_bullet()
{
	int		i = -1;
	while (++i < NUM_BULLETS)
	{
		if (!(this->CONTAINER_BULLET[i].isActive()))
			return (&(this->CONTAINER_BULLET[i]));
	}
	return NULL;
}

Star				*MGR_Game::spawn_star()
{
	int		i = -1;
	while (++i < NUM_STARS)
	{
		if (!(this->CONTAINER_STAR[i].isActive()))
			return (&(this->CONTAINER_STAR[i]));

	}
	return NULL;
}

Powerup				*MGR_Game::spawn_powerup()
{
	int		i = -1;
	while (++i < NUM_POWERUPS)
	{
		if (!(this->CONTAINER_POWERUP[i].isActive()))
		{

			return (&(this->CONTAINER_POWERUP[i]));
		}
	}
	return NULL;
}

int					MGR_Game::get_num_active_enemy()
{
	int		i = -1;
	int		num_active = 0;
	while (++i < NUM_ENEMIES)
	{
		if (this->CONTAINER_ENEMY[i].isActive())
			num_active++;
	}
	return (num_active);
}

int					MGR_Game::get_num_active_bullet()
{
	int		i = -1;
	int		num_active = 0;
	while (++i < NUM_BULLETS)
	{
		if (this->CONTAINER_BULLET[i].isActive())
			num_active++;
	}
	return (num_active);
}

int					MGR_Game::get_num_active_star()
{
	int		i = -1;
	int		num_active = 0;
	while (++i < NUM_STARS)
	{
		if (this->CONTAINER_STAR[i].isActive())
			num_active++;
	}
	return (num_active);
}

int					MGR_Game::get_num_active_powerup()
{
	int		i = -1;
	int		num_active = 0;
	while (++i < NUM_POWERUPS)
	{
		if (this->CONTAINER_POWERUP[i].isActive())
			num_active++;
	}
	return (num_active);
}

MGR_Game*			MGR_Game::getInstance()
{
	static MGR_Game		instance; // Guaranteed to be destroyed.
	// Instantiated on first use.
	return &instance;
}

MGR_Game::MGR_Game() {}

MGR_Game::~MGR_Game() {}

MGR_Game::MGR_Game(MGR_Game const& rhs)
{
	(void)rhs;
	return ;
}

MGR_Game&			MGR_Game::operator=(MGR_Game const & rhs)
{
	(void)rhs;
	return (*this);
}
