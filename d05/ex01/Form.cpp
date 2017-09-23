/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
name("Form"), grade_signature(1), grade_execute(1)
{
	this->is_signed = false;
	return;
}

Form::Form(std::string name, int gradeSign, int gradeExecute) :
name(name), grade_signature(gradeSign), grade_execute(gradeExecute)
{
	this->is_signed = false;
	if (this->grade_signature > GRADE_LOW || this->grade_execute > GRADE_LOW)
		throw Bureaucrat::GradeTooLowException();
	else if (this->grade_signature < GRADE_HIGH || this->grade_execute < GRADE_HIGH)
		throw Bureaucrat::GradeTooHighException();
	return;
}

void Form::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > this->grade_signature)
		throw Form::GradeTooLowException();
	else
		this->is_signed = true;
}


std::ostream & operator<<(std::ostream & o, Form & rhs)
{
	o << "Name: " << rhs.getName() << " Grade Sign: " << rhs.getGradeSign()
	  << " Grade Execute: " << rhs.getGradeExecute() << " Signed: " << rhs.getSigned()
	  << std::endl;
	return o;
}

Form & Form::operator=(Form const & rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const & rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const & rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High Exception";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low Exception";
}

Form::Form(Form const & src) :
name(src.name), grade_signature(src.grade_signature), grade_execute(src.grade_execute)
{
	*this = src;
	return;
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src)
{
	*this = src;
}

Form::GradeTooHighException::GradeTooHighException(void) {}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}
Form::GradeTooLowException::GradeTooLowException(void) {}
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}
Form::~Form(void) {}
std::string Form::getName() const { return this->name; }
int Form::getGradeSign() const { return this->grade_signature; }
int Form::getGradeExecute() const { return this->grade_execute; }
bool Form::getSigned() const { return this->is_signed; }