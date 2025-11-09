/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:49:42 by kevwang           #+#    #+#             */
/*   Updated: 2025/10/24 15:49:44 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c);