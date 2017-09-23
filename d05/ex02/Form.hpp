/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM__
#define __FORM__

#include "Bureaucrat.hpp"

class			Form
{
protected:
	const std::string	target;
	const std::string	name;
	const int			grade_signature;
	const int			grade_execute;
	bool				is_signed;
	Form(void);
public:
	Form(std::string target, std::string name, int gradeSign, int gradeExecute);
	Form(Form const & src);
	~Form(void);
	Form & operator=(Form const & rhs);

	std::string		getName() const;
	int				getGradeSign() const;
	int				getGradeExecute() const;
	bool			getSigned() const;
	std::string		getTarget() const;

	virtual void	execute(Bureaucrat const & executor) const = 0;
	void			beSigned(Bureaucrat & bureaucrat);

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
	class IsNotSignedException : public std::exception
	{
	public:
		IsNotSignedException(void);
		IsNotSignedException(IsNotSignedException const & src);
		virtual ~IsNotSignedException(void) throw();

		IsNotSignedException & operator=(IsNotSignedException const & rhs);

		virtual const char * what() const throw();
	};

};
std::ostream & operator<<(std::ostream & o, Form & rhs);
#endif