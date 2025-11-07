#pragma once

#include <iostream>
#include <string>

class AForm
{
private:
	const std::string name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_exec;

public:
	AForm();
	AForm(const std::string &name, int grade_to_sign, int grade_to_exec);
	~AForm();
	AForm(const AForm &copy);
	AForm &operator=(const AForm &other);

	virtual const std::string getName() const;
	virtual bool getIsSigned() const;
	virtual int getGradeToSign() const;
	virtual int getGradeToExec() const;

	// void beSigned(Bureaucrat buro);

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


// std::ostream &operator<<(std::ostream &out, const Bureaucrat &c);