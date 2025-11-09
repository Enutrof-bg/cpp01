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

int main()
{
	std::cout << "Test1" << std::endl;
	try
	{
		Bureaucrat albert("ALbert", 120);
		std::cout << albert << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Erreur grade: " << e.what() << std::endl;
	}

	std::cout << "\nTest2" << std::endl;
	try
	{
		Bureaucrat bernard("bernard", 151);
		std::cout << bernard << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Erreur grade:v" << e.what() << std::endl;
	}

	std::cout << "\nTest3" << std::endl;
	try
	{
		Bureaucrat charle("charlee", 0);
		std::cout << charle << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Erreur grade:v" << e.what() << std::endl;
	}
	return (0);
}
