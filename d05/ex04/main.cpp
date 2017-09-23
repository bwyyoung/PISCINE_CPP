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

#include "OfficeBlock.hpp"


void	test_president()
{
	{
		Bureaucrat					b1("B1", 150);
		try
		{
			ShrubberyCreationForm	 	test01("SCF_1");
			RobotomyRequestForm	 		test02("RRF_1");
			PresidentialPardonForm	 	test03("PDF_1");
			std::cout << b1 << std::endl;
			std::cout << test01 << std::endl;
			std::cout << test02 << std::endl;
			std::cout << test03 << std::endl;
			b1.signForm(test01);
			b1.signForm(test02);
			b1.signForm(test03);
			b1.executeForm(test01);
			b1.executeForm(test02);
			b1.executeForm(test03);
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat					b2("B2", 20);
			ShrubberyCreationForm	 	test01("SCF_2");
			RobotomyRequestForm	 		test02("RRF_2");
			PresidentialPardonForm	 	test03("PDF_2");
			std::cout << b2 << std::endl;
			std::cout << test01 << std::endl;
			std::cout << test02 << std::endl;
			std::cout << test03 << std::endl;
			b2.signForm(test01);
			b2.signForm(test02);
			b2.signForm(test03);
			b2.executeForm(test01);
			b2.executeForm(test02);
			b2.executeForm(test03);
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat					b3("B3", 1);
			PresidentialPardonForm	 	test01("PDF_3");
			std::cout << b3 << std::endl;
			std::cout << test01 << std::endl;
			b3.signForm(test01);
			b3.executeForm(test01);
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat				b4("B4", 70);
			RobotomyRequestForm	 	test01("RRF_4");
			std::cout << b4 << std::endl;
			std::cout << test01 << std::endl;
			b4.signForm(test01);
			b4.executeForm(test01);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat					b5("B5", 140);
			ShrubberyCreationForm	 	test01("SCF_5");
			std::cout << b5 << std::endl;
			std::cout << test01 << std::endl;
			b5.signForm(test01);
			b5.executeForm(test01);
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
}

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

void	test_intern()
{
	Bureaucrat b1 = Bureaucrat("The Bureaucrat 1", 40);
	Intern i1;
	Form *f1;
	Form *f2;
	Form *f3;
	Form *f4;

	f1 = i1.makeForm("robotomy request", "Bender");
	f2 = i1.makeForm("presidential pardon", "Bender");
	f3 = i1.makeForm("shrubbery creation", "Bender");
	std::cout << *f1;
	std::cout << *f2;
	std::cout << *f3;
	b1.signForm(*f1);
	b1.signForm(*f2);
	b1.signForm(*f3);
	f4 = i1.makeForm("TEST", "Bender");
}

void test_officeblock()
{
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 1);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 20);
	OfficeBlock ob;
	OfficeBlock emptyblock;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	try
	{
		emptyblock.doBureaucracy("robotomy request", "Pigley");
		ob.doBureaucracy("robotomy request", "Pigley");
	}
	catch (Form::IsNotSignedException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Intern::FormNotFound & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

int		main()
{
	test_officeblock();
	return (0);
}