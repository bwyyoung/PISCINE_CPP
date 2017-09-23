/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  IMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 19:13:40 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/03 09:11:29 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#include "IMonitorModule.hpp"


IMonitorModule::IMonitorModule(std::string name, std::string type)
{
	size_t		height = 0;
	size_t		i = 0;
	this->_moduleName = name;
	this->type = type;
	if (this->type == MODULE_TYPE_LARGE)
		height = MODULE_LARGE_HEIGHT;
	else if (this->type == MODULE_TYPE_SMALL)
		height = MODULE_SMALL_HEIGHT;
	while (i < height)
	{
		this->text_box.push_back("");
		i++;
	}
}
std::string*				IMonitorModule::getDatas()
{
	return NULL;
}


int						IMonitorModule::getWidth()
{
	if (this->type == MODULE_TYPE_LARGE)
		return MODULE_LARGE_WIDTH;
	return MODULE_SMALL_WIDTH;
}

int						IMonitorModule::getHeight()
{
	if (this->type == MODULE_TYPE_LARGE)
		return MODULE_LARGE_HEIGHT;
	return MODULE_SMALL_HEIGHT;
}

IMonitorModule::~IMonitorModule()
{

}

void					IMonitorModule::update_data(std::string *array)
{
	UNUSED(array);
}

std::string				IMonitorModule::centered(std::string const& original,
		size_t targetSize, char padchar)
{
	if (original.empty())
		return original;
	return std::string((targetSize - original.length()) / 2, padchar)
		   + original;
}

void					IMonitorModule::refresh_render_data(
									std::vector<std::string> strings)
{
	std::string		current_type;
	size_t				current_height = 0;
	size_t				current_width = 0;
	size_t				i = 1;
	if (this->type == MODULE_TYPE_SMALL)
	{
		current_type = MODULE_TYPE_SMALL;
		current_height = MODULE_SMALL_HEIGHT;
		current_width = MODULE_SMALL_WIDTH;
	}
	else if (this->type == MODULE_TYPE_LARGE)
	{
		current_type = MODULE_TYPE_LARGE;
		current_height = MODULE_LARGE_HEIGHT;
		current_width = MODULE_LARGE_WIDTH;
	}
	text_box[0] = std::string(current_width, '-');
	for (std::vector<std::string>::iterator it = strings.begin();
		it != strings.end(); ++it)
	{
		text_box[i] = this->centered(*it, current_width, ' ');
		i++;
	}
	while (i < current_height)
	{
		text_box[i]  = std::string(current_width, ' ');
		i++;
	}
}

std::vector<std::string>	IMonitorModule::get_render_data()
{
	return text_box;
}