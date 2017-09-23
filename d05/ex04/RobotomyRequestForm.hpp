/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ROBOTOMY_
#define _ROBOTOMY_

#include "Bureaucrat.hpp"
#include "Form.hpp"

class						RobotomyRequestForm : public Form
{
private:
	RobotomyRequestForm(void);
	static const int sign;
	static const int exec;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm&		operator=(RobotomyRequestForm const & rhs);
	~RobotomyRequestForm();
	void execute(Bureaucrat const & executor) const;
};

#endif
