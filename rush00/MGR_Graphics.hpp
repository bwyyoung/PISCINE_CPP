/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Graphics.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MGR_GRAPHICS__
#define __MGR_GRAPHICS__

#include <ncurses.h>
#include "IEntity.hpp"
#include <thread>

#define WORLD_WIDTH 100
#define WORLD_HEIGHT 40
#define DELAY 600000

class	MGR_Graphics
{
public:
	//Coplein
	~MGR_Graphics(void);
	static MGR_Graphics*	getInstance();
	void					Graphics_Start();
	void					Graphics_End();
	int						get_map_min_x();
	int						get_map_max_x();
	int						get_map_min_y();
	int						get_map_max_y();
	void					Render_Start();
	void					Render_Entity(IEntity *theEntity);
	void					Render_End();
	void					print_message(std::string str);
private:
	MGR_Graphics(void);
	MGR_Graphics(MGR_Graphics const & src);
	MGR_Graphics &			operator=(MGR_Graphics const & src);

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