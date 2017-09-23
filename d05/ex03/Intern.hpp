/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __INTERN__
# define __INTERN__

#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(Intern const & src);
	~Intern(void);
	Intern & operator=(Intern const & rhs);

	Form *		searchForm(std::string nameForm, std::string targetForm);
	Form *		makeForm(std::string nameForm, std::string targetForm);

	Form *		robotomyRequest(std::string const & target);
	Form *		presidentialPardon(std::string const & target);
	Form *		shrubberyCreation(std::string const & target);
	class FormNotFound : public std::exception
	{
	public:
		FormNotFound(void);
		FormNotFound(FormNotFound const & src);
		virtual ~FormNotFound(void) throw();
		FormNotFound & operator=(FormNotFound const & rhs);
		virtual const char * what() const throw();
	};
};
#endif
