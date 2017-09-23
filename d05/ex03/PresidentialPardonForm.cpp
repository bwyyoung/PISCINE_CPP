/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::sign = 25;
const int PresidentialPardonForm::exec = 5;

PresidentialPardonForm::PresidentialPardonForm(void) :
		Form("Anonymous", "Presidential", PresidentialPardonForm::sign, PresidentialPardonForm::exec)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
Form(target, "Presidential", PresidentialPardonForm::sign, PresidentialPardonForm::exec)
{}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
		Form("Anonymous", "Presidential", PresidentialPardonForm::sign, PresidentialPardonForm::exec)
{
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	(void)rhs;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);

	std::cout << "<" << this->getTarget() << "> has been pardoned by Zafod Beeblebrox." << std::endl;
}
