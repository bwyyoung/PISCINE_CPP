/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <iostream>
#include <string>

#define GRADE_LOW 150
#define GRADE_HIGH 1

class			Form;

class			Bureaucrat
{
private:
	std::string	const		name;
	int						grade;
	Bureaucrat(void);
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat&				operator=(Bureaucrat const & rhs);
	virtual					~Bureaucrat();
	int						getGrade() const;
	std::string				getName() const;
	void					incGrade();
	void					decGrade();
	void					signForm(Form & form);
	void					executeForm(Form const & form);

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const & src);
		virtual ~GradeTooHighException(void) throw();
		GradeTooHighException & operator=(GradeTooHighException const & rhs);
		virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const & src);
		virtual ~GradeTooLowException(void) throw();
		GradeTooLowException & operator=(GradeTooLowException const & rhs);
		virtual const char * what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs);

#endif