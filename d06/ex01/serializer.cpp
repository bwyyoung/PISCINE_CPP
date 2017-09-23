/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

serializer* serializer::getInstance()
{
	static serializer		instance;
	return (&instance);
}

serializer::serializer()
{
	list = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	this->alphanumeric = new char[list.length() + 1];
	std::memcpy(this->alphanumeric, list.c_str(), list.length());
	this->alphanumeric[list.length() + 1] = '\0';
	data = new Data();
}

serializer::~serializer()
{
	std::cout << "END SERIALIZER" << std::endl;
	delete this->alphanumeric;
	delete this->data;
}

serializer::serializer(serializer const& rhs)
{
	static_cast<void>(rhs);
	return ;
}

serializer&			serializer::operator=(serializer const & rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

char*				serializer::get_alphanumeric()
{
	return this->alphanumeric;
}

std::string			serializer::get_list()
{
	return this->list;
}

Data*				serializer::get_data()
{
	return this->data;
}