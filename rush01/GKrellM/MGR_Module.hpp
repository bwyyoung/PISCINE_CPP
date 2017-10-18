/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Module.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MGR_MODULE_HPP
#define MGR_MODULE_HPP
#include "modules/Module_CAT.hpp"
#include "modules/Module_HOST.hpp"
#include "modules/Module_MemRegions.hpp"
#include "modules/Module_DISK.hpp"
#include "modules/Module_CPU.hpp"
#include "modules/Module_Network.hpp"
#include "modules/Module_OS.hpp"
#include "modules/Module_PONY.hpp"
#include "modules/Module_PROC.hpp"
#include "modules/Module_RAM.hpp"
#include "modules/Module_TIME.hpp"
#include "modules/Module_VM.hpp"
#include <map>
#include <mutex>
#include <stdio.h>
# undef		scroll
# undef		timeout
# undef		border

class MGR_Module
{
public:
	~MGR_Module(void);
	static MGR_Module*		getInstance();
	void					init_modules();
	int						fetch_system_data();
	void					decorate_data();
	void 					Render_Terminal();
	void 					Render_QT();
	void					QUIT();
	IMonitorModule*			get_module(std::string themodule);
private:
	static bool 			is_quit;
	static					MGR_Module *singletonInstance;
	static					std::mutex m_;
	FILE					*stream;
	MGR_Module(void);
	MGR_Module(MGR_Module const & src);
	MGR_Module &			operator=(MGR_Module const & src);
	std::map<std::string, IMonitorModule*>	MODULE_CONTAINER;
	std::map<std::string, IMonitorModule*>	MODULE_CONTAINER_EXTRA;
	bool 				update_PROC(char *charbuf, size_t &pos, size_t &len, std::string *storage);
	bool				update_CPU(char *charbuf, size_t &pos, size_t &len, std::string *storage);
	bool				update_MemRegions(char *charbuf, size_t &pos, size_t &len, std::string *storage);
	bool				update_MEM(char *charbuf, size_t &pos, size_t &len, std::string *storage);
	bool				update_VM(char *charbuf, size_t &pos, size_t &len, std::string *storage);
	bool				update_NETWORK(char *charbuf, size_t &pos, size_t &len, std::string *storage);
	bool				update_DISKS(char *charbuf, size_t &pos, size_t &len, std::string *storage);
};

#endif
