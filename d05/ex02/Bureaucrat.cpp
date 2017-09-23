/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	if (this->grade > GRADE_LOW)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade < GRADE_HIGH)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
	return;
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this == &rhs)
		return *this;
	this->grade = rhs.grade;
	return *this;
}

void					Bureaucrat::incGrade(void)
{
	if ((this->grade - 1) < GRADE_HIGH)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void					Bureaucrat::decGrade(void)
{
	if ((this->grade + 1) > GRADE_LOW)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs)
{
	o << "<" << rhs.getName() << ">" << ", bureaucrat grade <" << rhs.getGrade() << ">" << std::endl;
	return o;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}


const char *			Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High Exception";
}

const char *			Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low Exception";
}

void			Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "<" << this->name << "> signs <" << form.getName() << ">"
				  << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "<" << this->name << "> cannot sign <" << form.getName()
				  << "> because <" << e.what() << ">" << std::endl;
	}
}

void			Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << "<" << this->name << "> executes <" << form.getName() << ">" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "<" << this->name << "> cannot execute <" << form.getName() << "> because <"
				  << e.what() << ">" << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}
Bureaucrat::Bureaucrat(void) {}
Bureaucrat::~Bureaucrat() {}
int						Bureaucrat::getGrade() const { return this->grade; }
std::string				Bureaucrat::getName() const { return name; }