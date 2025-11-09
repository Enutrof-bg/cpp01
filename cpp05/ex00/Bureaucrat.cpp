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
	// std::cout << "Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Default Destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	// std::cout << "Default Copy Constructor" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	// std::cout << "Default Assignment Constructor" << std::endl;
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
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c)
{
    out << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
    return out;
}