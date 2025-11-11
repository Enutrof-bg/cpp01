#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_exec;

public:
	Form();
	Form(const std::string &name, int grade_to_sign, int grade_to_exec);
	~Form();
	Form(const Form &copy);
	Form &operator=(const Form &other);

	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(Bureaucrat buro);

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


std::ostream &operator<<(std::ostream &out, const Form &c);