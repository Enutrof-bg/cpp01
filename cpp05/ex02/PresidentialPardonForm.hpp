#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;

public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	const std::string getTarget() const;

	void execute(Bureaucrat const & executor)const;

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

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &f);