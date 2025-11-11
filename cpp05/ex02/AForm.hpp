#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_exec;

public:
	AForm();
	AForm(const std::string &name, int grade_to_sign, int grade_to_exec);
	virtual ~AForm();
	AForm(const AForm &copy);
	AForm &operator=(const AForm &other);

	virtual const std::string getName() const;
	virtual bool getIsSigned() const;
	virtual int getGradeToSign() const;
	virtual int getGradeToExec() const;

	virtual void beSigned(Bureaucrat buro);

	virtual void execute(Bureaucrat const & executor)const = 0;

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

	class NotSignedException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};

	class GradeTooLowExecException : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};

	class OpenFailed : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &c);