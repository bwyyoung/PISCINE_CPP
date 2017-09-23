/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Uodule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_Module.hpp"
#include "displays/MGR_QT.hpp"

bool 				MGR_Module::is_quit = false;

MGR_Module*			MGR_Module::singletonInstance = nullptr;
std::mutex			MGR_Module::m_;

MGR_Module*			MGR_Module::getInstance()
{
	std::lock_guard<std::mutex> lock(m_);
	if(singletonInstance == nullptr)
		singletonInstance = new MGR_Module();
	return singletonInstance;
}

MGR_Module::MGR_Module()
{
	init_modules();
}

MGR_Module::~MGR_Module()
{
	this->QUIT();
}

void				MGR_Module::QUIT()
{
	MGR_Module::is_quit = true;
	for(std::map<std::string, IMonitorModule*>::iterator itr =
			MODULE_CONTAINER.begin(); itr != MODULE_CONTAINER.end(); ++itr)
	{
		if (itr->second)
			delete itr->second;
		itr->second = NULL;
	}
	for(std::map<std::string, IMonitorModule*>::iterator itr =
			MODULE_CONTAINER_EXTRA.begin(); itr != MODULE_CONTAINER_EXTRA.end(); ++itr)
	{
		if (itr->second)
			delete itr->second;
		itr->second = NULL;
	}
	MODULE_CONTAINER.clear();
	MODULE_CONTAINER_EXTRA.clear();
}

void				MGR_Module::decorate_data()
{
	if (MGR_Module::is_quit)
		return;
	for(std::map<std::string, IMonitorModule*>::iterator itr =
			MODULE_CONTAINER.begin(); itr != MODULE_CONTAINER.end(); ++itr)
		itr->second->refresh_datas();
	for(std::map<std::string, IMonitorModule*>::iterator itr =
	MODULE_CONTAINER_EXTRA.begin(); itr != MODULE_CONTAINER_EXTRA.end(); ++itr)
		itr->second->refresh_datas();
}

void				MGR_Module::Render_Terminal()
{
	if (MGR_Module::is_quit)
		return ;
	int			x = 0;
	int			y = 0;
	std::string	type;
	for(std::map<std::string, IMonitorModule*>::iterator itr =
			MODULE_CONTAINER.begin(); itr != MODULE_CONTAINER.end(); ++itr)
	{
		MGR_NCURSES::getInstance()->Render_String_Block
				(itr->second->get_render_data(), x, y);
		x += itr->second->getWidth();
		if (x >= WORLD_WIDTH)
		{
			x = 0;
			y += itr->second->getHeight();
		}
	}
	for(std::map<std::string, IMonitorModule*>::iterator itr =
			MODULE_CONTAINER_EXTRA.begin(); itr != MODULE_CONTAINER_EXTRA.end(); ++itr)
	{
		MGR_NCURSES::getInstance()->Render_String_Block
				(itr->second->get_render_data(), x, y);
		x += itr->second->getWidth();
		if (x >= WORLD_WIDTH)
		{
			x = 0;
			y += itr->second->getHeight();
		}
	}
}

void				MGR_Module::Render_QT()
{
	if (MGR_Module::is_quit)
		return ;
	int			x = 0;
	int			y = 0;
	std::string	type;
	for(std::map<std::string, IMonitorModule*>::iterator itr =
			MODULE_CONTAINER.begin(); itr != MODULE_CONTAINER.end(); ++itr)
	{
		MGR_QT::getInstance()->Render_String_Block
				(itr->second->get_render_data(), x, y);
		x++;
		if (x >= NUM_MODULE_ROW)
		{
			x = 0;
			y++;
		}
	}
	for(std::map<std::string, IMonitorModule*>::iterator itr =
			MODULE_CONTAINER_EXTRA.begin(); itr != MODULE_CONTAINER_EXTRA.end(); ++itr)
	{
		MGR_QT::getInstance()->Render_String_Block
				(itr->second->get_render_data(), x, y);
		x++;
		if (x >= NUM_MODULE_ROW)
		{
			x = 0;
			y++;
		}
	}
}

IMonitorModule*			MGR_Module::get_module(std::string themodule)
{
	return this->MODULE_CONTAINER[themodule];
}


MGR_Module::MGR_Module(MGR_Module const& rhs)
{
	UNUSED(rhs);
	return ;
}

MGR_Module&			MGR_Module::operator=(MGR_Module const & rhs)
{
	UNUSED(rhs);
	return (*this);
}

void				MGR_Module::init_modules()
{
	MODULE_CONTAINER[MODULE_HOST]		= new Module_HOST();
	MODULE_CONTAINER[MODULE_OS]			= new Module_OS();
	MODULE_CONTAINER[MODULE_TIME]		= new Module_TIME();
	MODULE_CONTAINER[MODULE_CPU]		= new Module_CPU();
	MODULE_CONTAINER[MODULE_PROC]		= new Module_PROC();
	MODULE_CONTAINER[MODULE_RAM]		= new Module_RAM();
	MODULE_CONTAINER[MODULE_VM]			= new Module_VM();
	MODULE_CONTAINER[MODULE_DISK]		= new Module_DISK();
	MODULE_CONTAINER[MODULE_MEMREGIONS] = new Module_MemRegions();
	MODULE_CONTAINER[MODULE_NETWORK]	= new Module_Network();
	MODULE_CONTAINER_EXTRA[MODULE_PONY]		= new Module_PONY();
	MODULE_CONTAINER_EXTRA[MODULE_CAT]		= new Module_CAT();
}

