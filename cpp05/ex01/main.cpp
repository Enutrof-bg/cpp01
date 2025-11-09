/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:49:28 by kevwang           #+#    #+#             */
/*   Updated: 2025/10/24 15:49:29 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "Test 1" << std::endl;
	try
	{
		Bureaucrat albert("Albert", 5);
		Form formulaire("FormulaireA", 10, 20);

		albert.signForm(formulaire);
		std::cout << albert << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Erreur:  " << e.what() << std::endl;
	}

	std::cout << "\nTest 2" << std::endl;
	try
	{
		Bureaucrat bernard("Bernard", 148);
		Form formulaireB("FormulaireB", 145, 25);

		bernard.signForm(formulaireB);
		std::cout << bernard << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Erreur:  " << e.what() << std::endl;
	}


	std::cout << "\nTest 3" << std::endl;
	try
	{
		Bureaucrat charle("charle", 2);
		charle.incrementGrade();
		charle.incrementGrade();
		charle.incrementGrade();

		Form formulaireC("FormulaireC", 1, 30);
		charle.signForm(formulaireC);
		std::cout << charle << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Erreur:  " << e.what() << std::endl;
	}


	std::cout << "\nTest4" << std::endl;
	try
	{
		Bureaucrat david("david", 5);
		Form formulaireD("FormulaireD", 5, 40);
		david.signForm(formulaireD);
		std::cout << david << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Erreur:  " << e.what() << std::endl;
	}


	std::cout << "\nTest5" << std::endl;
	try
	{
		Bureaucrat eric("eric", 43);
		Bureaucrat filip("filip", 123);
		Bureaucrat gerard("gerard", 132);

		Form formulaireE("FormulaireE", 100, 50);
		eric.signForm(formulaireE);
		filip.signForm(formulaireE);
		gerard.signForm(formulaireE);
		std::cout << eric << std::endl;
		std::cout << filip << std::endl;
		std::cout << gerard << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Erreur:  " << e.what() << std::endl;
	}
	return (0);
}
