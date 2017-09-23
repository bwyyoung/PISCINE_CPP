/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 13:49:21 by ybarbier          #+#    #+#             */
/*   Updated: 2015/06/19 15:48:16 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"



void		test_2()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* zaz = new Character("zaz");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);

	ICharacter* bob = new Character("bob");

	std::cout << "tmp xp before materia uses : " << tmp->getXP() << std::endl;
	zaz->use(0, *bob);
	std::cout << "tmp xp after other materia use  : " << tmp->getXP() << std::endl;
	zaz->use(1, *bob);
	std::cout << "tmp xp after own use : " << tmp->getXP() << std::endl;

	std::cout << "Adding three other materias to the materiaSource, should only be able to add the first two of them" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	std::cout << "Equiping zaz until full" << std::endl;
	zaz->equip(src->createMateria("cure"));
	zaz->equip(src->createMateria("cure"));
	zaz->equip(src->createMateria("cure"));

	std::cout << "using new materias" << std::endl;
	zaz->use(2, *bob);
	zaz->use(3, *bob);
	std::cout << "calling zaz->use(4, *bob) should do nothing : " << std::endl;
	zaz->use(4, *bob);

	std::cout << std::endl << "using tmp again, and showing xp : " << std::endl;
	zaz->use(1, *bob);
	std::cout << "tmp xp : " << tmp->getXP() << std::endl;

	delete bob;
	delete zaz;
	delete src;
}

void		test_1()
{
	IMateriaSource* src = new MateriaSource();
	AMateria* tmp;
	std::cout << "---> Try to create new Materias from Materia Source:" << std::endl;
	tmp = src->createMateria("ice");
	std::cout << std::endl << "---> Fill up Materia Source with new Materias:" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	ICharacter* zaz = new Character("zaz");
	ICharacter* bob = new Character("bob");
	std::cout << std::endl << "---> Equip Character with new Materias created from Materia Source:" << std::endl;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	zaz->equip(tmp);
	zaz->equip(tmp);
	zaz->equip(tmp);
	std::cout << std::endl << "---> Attack Bob with Materias :" << std::endl;
	zaz->use(0, *bob);
	zaz->use(1, *bob);
	zaz->use(2, *bob);
	zaz->use(2, *bob);
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	zaz->use(0, *bob);
	std::cout << std::endl << "---> Unequip all Materias :" << std::endl;
	zaz->unequip(3);
	zaz->unequip(2);
	delete bob;
	delete zaz;
	delete src;
}

void		test_default()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* zaz = new Character("zaz");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	ICharacter* bob = new Character("bob");
	zaz->use(0, *bob);
	zaz->use(1, *bob);
	delete bob;
	delete zaz;
	delete src;
}

int			main()
{
	std::cout << "-----DEFAULT_TEST----" << std::endl;
	test_default();
	std::cout << "-----TEST_1----" << std::endl;
	test_1();
	std::cout << "-----TEST_2----" << std::endl;
	test_2();
	return (0);
}