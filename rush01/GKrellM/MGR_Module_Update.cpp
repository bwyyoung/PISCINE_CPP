/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Module_Update.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_Module.hpp"

int					MGR_Module::fetch_system_data()
{
	char				charbuf[256];
	size_t				pos;
	size_t				len;
	std::string			storage[5];

	try
	{
		if (MGR_Module::is_quit)
			return 0;
		if (!(this->stream = popen("top -l 1 -n 0 -s 0", "r")))
			return 0;
		if (std::fgets(charbuf, 256, this->stream) == NULL)
			return pclose(this->stream);
		if (!this->update_PROC(charbuf, pos, len, storage))
			return pclose(this->stream);
		if (!this->update_CPU(charbuf, pos, len, storage))
			return pclose(this->stream);
		if (!this->update_MemRegions(charbuf, pos, len, storage))
			return pclose(this->stream);
		if (!this->update_MEM(charbuf, pos, len, storage))
			return pclose(this->stream);
		if (!this->update_VM(charbuf, pos, len, storage))
			return pclose(this->stream);
		if (!this->update_NETWORK(charbuf, pos, len, storage))
			return pclose(this->stream);
		if (!this->update_DISKS(charbuf, pos, len, storage))
			return pclose(this->stream);
		return pclose(this->stream);
	}
	catch (std::exception e)
	{
		UNUSED(e);
		//TODO: Log exceptions
	}
	return 0;
}

bool 				MGR_Module::update_PROC
		(char *charbuf, size_t &pos, size_t &len, std::string *storage)
{
	if (MGR_Module::is_quit)
		return false;
	pos = std::strcspn(charbuf, " ") + 1;
	storage[0].assign(charbuf, pos, std::strcspn(charbuf + pos, ","));
	pos += std::strcspn(charbuf + pos, " ") + 1;
	pos += std::strcspn(charbuf + pos, " ") + 1;
	len = std::strcspn(charbuf + pos, ",") + 1 ;
	len += std::strcspn(charbuf + pos + len, ",");
	storage[1].assign(charbuf, pos, len);
	pos += len + 2;
	len  = std::strcspn(charbuf + pos, "\0") - 2;
	storage[2].assign(charbuf, pos, len);
	MODULE_CONTAINER[MODULE_PROC]->update_data(storage);
	if (fgets(charbuf, 256, this->stream))
		if (fgets(charbuf, 256, this->stream))
			return (fgets(charbuf, 256, this->stream) != NULL);
	return false;
}

bool				MGR_Module::update_CPU
		(char *charbuf, size_t &pos, size_t &len, std::string *storage)
{
	if (MGR_Module::is_quit)
		return false;
	UNUSED(len);
	pos = std::strcspn(charbuf, " ") + 1;
	pos += std::strcspn(charbuf + pos, " ") + 1;
	storage[0].assign(charbuf, pos, std::strcspn(charbuf + pos, " "));
	pos += std::strcspn(charbuf + pos, " ") + 1;
	pos += std::strcspn(charbuf + pos, " ") + 1;
	storage[1].assign(charbuf, pos, std::strcspn(charbuf + pos, " "));
	pos += std::strcspn(charbuf + pos, " ") + 1;
	pos += std::strcspn(charbuf + pos, " ") + 1;
	storage[2].assign(charbuf, pos, std::strcspn(charbuf + pos, " "));
	MODULE_CONTAINER[MODULE_CPU]->update_data(storage);
	if (fgets(charbuf, 256, stream))
		return (fgets(charbuf, 256, stream) != NULL);
	return false;
}

bool				MGR_Module::update_MemRegions
		(char *charbuf, size_t &pos, size_t &len, std::string *storage)
{
	if (MGR_Module::is_quit)
		return false;
	pos = std::strcspn(charbuf, " ") + 1;
	storage[0].assign(charbuf, pos, std::strcspn(charbuf + pos, ","));
	pos += std::strcspn(charbuf + pos, " ") + 1;
	pos += std::strcspn(charbuf + pos, " ") + 1;
	len = std::strcspn(charbuf + pos, ",");
	storage[1].assign(charbuf, pos, len);
	pos += len + 2;
	len  = std::strcspn(charbuf + pos, "\0") - 2;
	storage[2].assign(charbuf, pos, len);
	MODULE_CONTAINER[MODULE_MEMREGIONS]->update_data(storage);
	return (fgets(charbuf, 256, stream) != NULL);
}

bool				MGR_Module::update_MEM
		(char *charbuf, size_t &pos, size_t &len, std::string *storage)
{
	if (MGR_Module::is_quit)
		return false;
	UNUSED(len);
	pos = std::strcspn(charbuf, " ") + 1;
	storage[0].assign(charbuf, pos, std::strcspn(charbuf + pos, "M"));
	pos = std::strcspn(charbuf, "(") + 1;
	storage[1].assign(charbuf, pos, std::strcspn(charbuf + pos, "M"));
	pos = std::strcspn(charbuf, ",") + 2;
	storage[2].assign(charbuf, pos, std::strcspn(charbuf + pos, "M"));
	MODULE_CONTAINER[MODULE_RAM]->update_data(storage);
	return (fgets(charbuf, 256, stream) != NULL);
}

bool				MGR_Module::update_VM
		(char *charbuf, size_t &pos, size_t &len, std::string *storage)
{
	if (MGR_Module::is_quit)
		return false;
	pos = std::strcspn(charbuf, " ") + 1;
	storage[0].assign(charbuf, pos, std::strcspn(charbuf + pos, ","));
	pos += std::strcspn(charbuf + pos, " ") + 1;
	pos += std::strcspn(charbuf + pos, " ") + 1;
	len = std::strcspn(charbuf + pos, ",");
	storage[1].assign(charbuf, pos, len);
	pos += len + 2;
	len = std::strcspn(charbuf + pos, ",");
	storage[2].assign(charbuf, pos, len);
	pos += len + 2;
	len  = std::strcspn(charbuf + pos, "\0") - 2;
	storage[3].assign(charbuf, pos, len);
	MODULE_CONTAINER[MODULE_VM]->update_data(storage);
	return (fgets(charbuf, 256, stream) != NULL);
}

bool				MGR_Module::update_NETWORK
		(char *charbuf, size_t &pos, size_t &len, std::string *storage)
{
	if (MGR_Module::is_quit)
		return false;
	UNUSED(len);
	pos = std::strcspn(charbuf, " ") + 1;
	pos += std::strcspn(charbuf + pos, " ") + 1;
	storage[0].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
	pos += std::strcspn(charbuf + pos, " ") + 1;
	pos += std::strcspn(charbuf + pos, " ") + 1;
	storage[1].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
	MODULE_CONTAINER[MODULE_NETWORK]->update_data(storage);
	return (fgets(charbuf, 256, stream) != NULL);
}

bool				MGR_Module::update_DISKS
		(char *charbuf, size_t &pos, size_t &len, std::string *storage)
{
	if (MGR_Module::is_quit)
		return false;
	UNUSED(len);
	pos = std::strcspn(charbuf, " ") + 1;
	storage[0].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
	pos += std::strcspn(charbuf + pos, " ") + 1;
	pos += std::strcspn(charbuf + pos, " ") + 1;
	storage[1].assign(charbuf, pos, std::strcspn(charbuf + pos, "/"));
	MODULE_CONTAINER[MODULE_DISK]->update_data(storage);
	return true;
}
