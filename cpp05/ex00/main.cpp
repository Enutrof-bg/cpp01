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
	std::cout << "test" << std::endl;
	// Bureaucrat buro;

	// std::cout << buro << std::endl;

	// Bureaucrat br2 = buro;

	// std::cout << br2 << std::endl;

	Bureaucrat test("ALbert", 99);
	std::cout << test << std::endl;

	test.incrementGrade();
	std::cout << test << std::endl;

	test.decrementGrade();
	std::cout << test << std::endl;
}
