/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Terminal_Time.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_Terminal.hpp"

DWORD				MGR_Terminal::GetTickCount()
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
	theTick  = (ts.tv_nsec / 1000000);
	theTick += (ts.tv_sec * 1000);
	return theTick;
}

void				MGR_Terminal::LOOP(void *threadid)
{
	UNUSED(threadid);
	DWORD			start_time = GetTickCount();
	DWORD			next_app_tick = start_time;
	DWORD			current;
	DWORD			elapsed;
	DWORD			sleep_time = 0;
	std::srand(static_cast<u_int>(time(NULL)));
	this->init_app();

	MGR_NCURSES::getInstance()->Graphics_Start();
	this->app_is_running = true;
	DWORD			seconds = 0;
	while(this->app_is_running)
	{
		current = GetTickCount();
		elapsed = current - start_time;
		seconds += elapsed;

		//Get User Input Based on Event received
		this->get_keyboard_event(); // frame based
		if (seconds > APP_REFRESH_RATE) //counting 1 second
		{
			//clock based
			seconds = 0;
			this->update_app();
			this->display_app();
		}
		next_app_tick += SKIP_TICKS;
		sleep_time = (next_app_tick - GetTickCount());
		if( sleep_time >= 0 )
		{
			//Sleep, we are running too fast
			std::chrono::milliseconds timespan(sleep_time);
			std::this_thread::sleep_for(timespan);
		}
		start_time = current;
	}
	MGR_NCURSES::getInstance()->Graphics_End();
}