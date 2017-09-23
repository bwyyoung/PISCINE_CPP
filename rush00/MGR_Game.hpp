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

#ifndef __MGR_GAME__
#define __MGR_GAME__
#include <time.h>
#include <sys/time.h>

#ifdef __MACH__
# include <mach/clock.h>
# include <mach/mach.h>
#endif

#include "MGR_Graphics.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Star.hpp"
#include "Powerup.hpp"
#define _POSIX_C_SOURCE >= 199309L

#ifdef WIN32
/* windows stuff */
#else
typedef unsigned long			DWORD;
typedef unsigned short			WORD;
typedef unsigned int			UNINT32;
#endif

#define GAME_REFRESH_RATE		250

#define ENTITY_CONTAINER_MAX	300
#define NUM_ENEMIES				5
#define NUM_STARS				100
#define NUM_POWERUPS			1
#define POWERUP_CHANCE			20
#define NUM_BULLETS				ENTITY_CONTAINER_MAX
#define FRAMES_PER_SECOND		60
#define SKIP_TICKS				1000 / FRAMES_PER_SECOND

#define STAR_SPAWN_RATE			5

#define MIN_NUM_ENEMIES			5
#define ENEMY_SPAWN_RATE		1

#define GAME_KEY_UP				65
#define GAME_KEY_DOWN			66
#define GAME_KEY_LEFT			68
#define GAME_KEY_RIGHT			67
#define GAME_KEY_SPACE			32
#define GAME_KEY_SPECIAL		91
#define GAME_KEY_ESC			27
#define GAME_KEY_INVALID		-1

#define DEBUG_DISABLE_ENEMY 	0

class	MGR_Game
{
public:
	//Coplein
	~MGR_Game(void);
	static MGR_Game*	getInstance();
	void				LOOP();
	Enemy				*spawn_enemy();
	Bullet				*spawn_bullet();
	Star				*spawn_star();
	Powerup				*spawn_powerup();
	int					get_num_active_enemy();
	int					get_num_active_bullet();
	int					get_num_active_star();
	int					get_num_active_powerup();
	int					getScore();
	void				increaseScore(int amount);
	void				player_power_up();
private:
	IEntity				*get_entity_grid(int x, int y);
	int					score;
	int					key_pressed;
	bool				keyboard_event();
	bool				game_is_running;
	MGR_Game(void);
	MGR_Game(MGR_Game const & src);
	MGR_Game &			operator=(MGR_Game const & src);
	DWORD				GetTickCount();
	void 				update_game_bottom_up();
	void 				update_game_top_down();
	void				update_game();
	void				update_stars();
	void				update_powerup();

	void				setup_spawn(IEntity *entity);
	void				update_spawn();
	void				display_game();
	void				get_keyboard_event();
	Enemy				CONTAINER_ENEMY[NUM_ENEMIES];
	Bullet				CONTAINER_BULLET[NUM_BULLETS];
	Star				CONTAINER_STAR[NUM_STARS];
	Powerup				CONTAINER_POWERUP[NUM_POWERUPS];
	Player				user;
	IEntity				*map_grid[WORLD_WIDTH][WORLD_HEIGHT];
	void				init_game();
	bool 				is_render;
	void				Remove_Entity_Grid(IEntity *entity);
	void				Update_Entity_Grid(IEntity *entity);
};

#endif