/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::FormNotFound::FormNotFound(void) {}
Intern::FormNotFound::~FormNotFound(void) throw() {}
Intern::Intern(void) {}
Intern::~Intern(void) {}

Intern::FormNotFound::FormNotFound(FormNotFound const & src)
{
	*this = src;
}


Intern::FormNotFound & Intern::FormNotFound::operator=(FormNotFound const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Intern::FormNotFound::what() const throw()
{
	return "Form NOT Found";
}

Intern::Intern(Intern const & src)
{
	*this = src;
	return;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

Form * Intern::searchForm(std::string nameForm, std::string targetForm)
{
	Form * (Intern::*form_types[3])(std::string const & target) =
	{
			&Intern::robotomyRequest,
			&Intern::presidentialPardon,
			&Intern::shrubberyCreation
	};
	const std::string form_names[] = {
			"robotomy request",
			"presidential pardon",
			"shrubbery creation"
	};

	for (int i = 0; i < 3; i++)
	{
		if (form_names[i].compare(nameForm) == 0)
		{
			std::cout << "Intern creates <" << nameForm << ">" << std::endl;
			return (this->*form_types[i])(targetForm);
		}
	}
	throw Intern::FormNotFound();
}

Form * Intern::makeForm(std::string nameForm, std::string targetForm)
{
	try
	{
		return Intern::searchForm(nameForm, targetForm);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return NULL;
}


Form *		Intern::robotomyRequest(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

Form *		Intern::presidentialPardon(std::string const & target)
{
	return new PresidentialPardonForm(target);
}

Form *		Intern::shrubberyCreation(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}