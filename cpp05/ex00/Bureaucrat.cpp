/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:49:39 by kevwang           #+#    #+#             */
/*   Updated: 2025/10/24 15:49:40 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150)
{
	std::cout << "Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
	// this->name = name;
	// this->grade = grade;
	if (grade > 150)
		throw grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "Default Copy Constructor" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Default Assignment Constructor" << std::endl;
	if (this != &other)
	{
		// name = other.getName();
		grade = other.getGrade();
	}
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}


void Bureaucrat::incrementGrade()
{
	grade--;
}

void Bureaucrat::decrementGrade()
{
	grade++;
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &c)
{
    out << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;;
    return out;
}