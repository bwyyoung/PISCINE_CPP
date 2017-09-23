/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PRESIDENT_
#define _PRESIDENT_

#include "Bureaucrat.hpp"
#include "Form.hpp"

class						PresidentialPardonForm : public Form
{
private:
	PresidentialPardonForm(void);
	static const int sign;
	static const int exec;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm&		operator=(PresidentialPardonForm const & rhs);
	~PresidentialPardonForm();
	void execute(Bureaucrat const & executor) const;
};

#endif
