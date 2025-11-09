#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	const std::string getTarget() const;

	void execute(Bureaucrat const & executor)const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &f);