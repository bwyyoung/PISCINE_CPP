/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_Terminal.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_Terminal.hpp"
#include "MGR_Module.hpp"

MGR_Terminal*			MGR_Terminal::singletonInstance = nullptr;
std::mutex				MGR_Terminal::m_;


void					MGR_Terminal::init_app()
{

}

MGR_Terminal*			MGR_Terminal::getInstance()
{
	std::lock_guard<std::mutex> lock(m_);
	if(singletonInstance == nullptr)
		singletonInstance = new MGR_Terminal();
	return singletonInstance;
}

MGR_Terminal::MGR_Terminal() {}

MGR_Terminal::~MGR_Terminal() {}

MGR_Terminal::MGR_Terminal(MGR_Terminal const& rhs)
{
	UNUSED(rhs);
	return ;
}

MGR_Terminal&			MGR_Terminal::operator=(MGR_Terminal const & rhs)
{
	UNUSED(rhs);
	return (*this);
}

void					MGR_Terminal::QUIT()
{
	this->app_is_running = false;
}
