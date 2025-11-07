#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShruberryCreationForm : public AForm
{
	ShruberryCreationForm(Bureaucrat target);
	~ShruberryCreationForm();
	ShruberryCreationForm(const ShruberryCreationForm &copy);
	ShruberryCreationForm &operator=(const ShruberryCreationForm &other);

	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
};