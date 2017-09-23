/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Terminal.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PISCINE_C_MGR_TERMINAL_HPP
#define PISCINE_C_MGR_TERMINAL_HPP
#include "displays/MGR_NCURSES.hpp"

# undef		scroll
# undef		timeout
# undef		border
 /** conflict between
  * 5.7/clang_64/lib/QtGui.framework/Headers/qpixmap.h:151:32:
  * error: too many arguments provided to function-like macro invocation
  * inline void scroll(int dx, int dy, int x, int y, int width, int height,
  * QRegion *exposed = Q_NULLPTR);
  *
  * AND
  *
  * /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform
  * /Developer/SDKs/MacOSX10.12.sdk/usr/include/ncurses.h:980:9:
  * note: macro 'scroll' defined here
  * #define scroll(win)             wscrl(win,1)
  *
  **/
#include <mutex>
#include "MGR_Module.hpp"
#ifdef __MACH__
# include <mach/clock.h>
# include <mach/mach.h>
#endif
#define _POSIX_C_SOURCE >= 199309L

#ifdef WIN32
/* windows stuff */
#else
typedef long					DWORD;
typedef unsigned long			UWORD;
typedef unsigned short			WORD;
typedef unsigned int			UNINT32;
#endif

#define APP_REFRESH_RATE		50
#define FRAMES_PER_SECOND		60
#define SKIP_TICKS				1000 / FRAMES_PER_SECOND

#define APP_KEY_UP				65
#define APP_KEY_DOWN			66
#define APP_KEY_LEFT			68
#define APP_KEY_RIGHT			67
#define APP_KEY_SPACE			32
#define APP_KEY_SPECIAL			91
#define APP_KEY_ESC				27
#define APP_KEY_INVALID			-1

class		MGR_QT;

class MGR_Terminal
{
public:
	//Coplein
	~MGR_Terminal(void);
	static MGR_Terminal*	getInstance();
	void					LOOP(void *threadid);
	void					QUIT();
private:
	static MGR_Terminal		*singletonInstance;
	static std::mutex		m_;
	void					init_app();
	MGR_Terminal(void);
	MGR_Terminal(MGR_Terminal const & src);
	MGR_Terminal &			operator=(MGR_Terminal const & src);
	int						key_pressed;
	bool					keyboard_event();
	void					get_keyboard_event();
	void					update_app();
	void					display_app();
	bool					app_is_running;
	DWORD					GetTickCount();
};


#endif
