/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void)
{
	signer = NULL;
	executor = NULL;
	intern = NULL;
	f = NULL;
	return;
}

OfficeBlock::OfficeBlock(OfficeBlock const & src)
{
	*this = src;
	return;
}

OfficeBlock::~OfficeBlock(void)
{
	return;
}

OfficeBlock & OfficeBlock::operator=(OfficeBlock const & rhs)
{
	(void)rhs;
	return *this;
}

void OfficeBlock::doBureaucracy(std::string form, std::string target)
{
	if (form.empty() || target.empty())
		return;
	if (!this->intern || !this->signer || !this->executor)
		throw StaffNotFoundException();
	f = this->intern->makeForm(form, target);
	if (!f)
		return ;
	this->signer->signForm(*f);
	this->executor->executeForm(*f);
}

void		OfficeBlock::setIntern(Intern & intern)
{
	this->intern = &intern;
}

void		OfficeBlock::setSigner(Bureaucrat & signer)
{
	this->signer = &signer;
}

void		OfficeBlock::setExecutor(Bureaucrat & executor)
{
	this->executor = &executor;
}

OfficeBlock::StaffNotFoundException::StaffNotFoundException(StaffNotFoundException const & src)
{
	*this = src;
}

OfficeBlock::StaffNotFoundException & OfficeBlock::StaffNotFoundException::operator=(StaffNotFoundException const & rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

const char * OfficeBlock::StaffNotFoundException::what() const throw()
{
	return "Staff Not Found To Perform This Operation";
}

OfficeBlock::StaffNotFoundException::StaffNotFoundException(void) {}
OfficeBlock::StaffNotFoundException::~StaffNotFoundException(void) throw() {}