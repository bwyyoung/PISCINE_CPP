/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
# include <time.h>
# include <sys/time.h>
# include <assert.h>
# include <iostream>
# include <Vector>
# include <Deque>
# include <ctime>
# include <wchar.h>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <sstream>
# include <cmath>
# include <iomanip>
# include <unistd.h>
# include <iostream>
# include <string>
# include "../displays/MGR_NCURSES.hpp"


#define NUM_MODULES 12
#define MODULE_SMALL_WIDTH WORLD_WIDTH / 5
#define MODULE_SMALL_HEIGHT 8
#define MODULE_LARGE_WIDTH WORLD_WIDTH / 2
#define MODULE_LARGE_HEIGHT 30


#define MODULE_CAT			"MODULE_CAT"
#define MODULE_CPU			"MODULE_CPU"
#define MODULE_DISK			"MODULE_DISK"
#define MODULE_HOST			"MODULE_HOST"
#define MODULE_MEMREGIONS	"MODULE_MEMREGIONS"
#define MODULE_NETWORK		"MODULE_NETWORK"
#define MODULE_OS			"MODULE_OS"
#define MODULE_PONY			"MODULE_PONY"
#define MODULE_PROC			"MODULE_PROC"
#define MODULE_RAM			"MODULE_RAM"
#define MODULE_TIME			"MODULE_TIME"
#define MODULE_VM			"MODULE_VM"

#define MODULE_TYPE_SMALL "SMALL"
#define MODULE_TYPE_LARGE "LARGE"
# define UNUSED(x)				static_cast<void>(x)


class IMonitorModule
{
public:
	IMonitorModule(std::string name, std::string type);
	virtual ~IMonitorModule();
	virtual void							update_data(std::string *array);
	virtual void							refresh_datas(void) = 0;
	virtual std::string const				&getModuleName(void) const = 0;
	virtual std::vector<std::string> const	&getStrings(void) const = 0;
	virtual std::deque<double> const			&getNumbers(void) const = 0;
	std::vector<std::string>				get_render_data(void);
	int										getWidth();
	int										getHeight();
	virtual std::string*					getDatas();
protected:
	std::string								_moduleName;
	std::string								type;
	void									refresh_render_data(
			std::vector<std::string> strings);
private:
	std::vector<std::string>				text_box;
	IMonitorModule(IMonitorModule const &src);
	IMonitorModule							&operator=(IMonitorModule const &rhs);
	std::string								centered(std::string const& original,
											size_t targetSize, char padchar);


};

#endif
