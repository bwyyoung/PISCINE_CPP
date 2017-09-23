/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


void	test_exception()
{
	{
		std::cout << std::endl << "Init: 3 Inc: 3" << std::endl;
		try
		{
			Bureaucrat b = Bureaucrat("test", 3);
			std::cout << b.getName() << std::endl;
			std::cout << b.getGrade() << std::endl;
			b.incGrade();
			std::cout << b.getGrade() << std::endl;
			b.incGrade();
			std::cout << b.getGrade() << std::endl;
			b.incGrade();
			std::cout << b.getGrade() << std::endl;
		}
		catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "Init: 148 Dec: 3" << std::endl;
		try
		{
			Bureaucrat b = Bureaucrat("test", 148);
			std::cout << b.getGrade() << std::endl;
			b.decGrade();
			std::cout << b.getGrade() << std::endl;
			b.decGrade();
			std::cout << b.getGrade() << std::endl;
			b.decGrade();
			std::cout << b.getGrade() << std::endl;
			b.incGrade();
			std::cout << b.getGrade() << std::endl;
		}
		catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "Init: 60 Inc: 2 Dec: 1" << std::endl;
		try
		{
			Bureaucrat b = Bureaucrat("test", 60);
			b.incGrade();
			std::cout << b.getGrade() << std::endl;
			b.incGrade();
			std::cout << b.getGrade() << std::endl;
			b.decGrade();
			std::cout << b.getGrade() << std::endl;

		}
		catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "Init: 151" << std::endl;
		try
		{
			Bureaucrat b = Bureaucrat("test", 151);
		}
		catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << "Init: 0" << std::endl;
		try
		{
			Bureaucrat b = Bureaucrat("test", 0);
		}
		catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat b = Bureaucrat("test", 60);
			std::cout << std::endl << b << std::endl;
			Bureaucrat a = Bureaucrat("HEY", 10);
			std::cout << a << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void	test_form()
{
	std::cout << "_____Form_____" << std::endl;
	{
		Bureaucrat b1 = Bureaucrat("The Bureaucrat 1", 40);
		Bureaucrat b2 = Bureaucrat("The Bureaucrat 2", 10);

		Form f1 = Form("Form 1", 50, 70);
		Form f2 = Form("Form 2", 20, 70);
		Form f3 = Form("Form 3", 30, 70);

		b1.signForm(f1);
		std::cout << b1;
		std::cout << f1 << std::endl;
		std::cout << std::endl;

		b1.signForm(f2);
		std::cout << b1;
		std::cout << f2 << std::endl;
		std::cout << std::endl;

		b2.signForm(f1);
		std::cout << b2;
		std::cout << f1 << std::endl;
		std::cout << std::endl;

		b2.signForm(f2);
		std::cout << b2;
		std::cout << f2 << std::endl;

		b2.signForm(f3);
		std::cout << b2;
		std::cout << f3 << std::endl;

		b1.signForm(f3);
		std::cout << b1;
		std::cout << f3 << std::endl;
	}
}

int		main()
{
	test_form();
	return (0);
}