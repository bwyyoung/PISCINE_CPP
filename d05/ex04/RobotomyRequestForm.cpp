/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


const int RobotomyRequestForm::sign = 72;
const int RobotomyRequestForm::exec = 45;

RobotomyRequestForm::RobotomyRequestForm(void) :
		Form("Anonymous", "Robotomy", RobotomyRequestForm::sign, RobotomyRequestForm::exec)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
		Form(target, "Robotomy", RobotomyRequestForm::sign, RobotomyRequestForm::exec)
{
	srand(time(NULL));
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
		Form("Anonymous", "Robotomy", RobotomyRequestForm::sign, RobotomyRequestForm::exec)
{
	srand(time(NULL));
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	(void)rhs;
	return *this;
}



void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);

	if (rand() % 2 == 1)
	{
		std::cout << "~~DRILL~~" << std::endl;
		std::cout << "<" << this->getTarget() << "> has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "<" << this->getTarget() << "> Robotomized failed" << std::endl;
	}
}
