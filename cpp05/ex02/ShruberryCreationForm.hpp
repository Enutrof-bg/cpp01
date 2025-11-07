#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShruberryCreationForm : public AForm
{
private:
	const std::string target;

public:
	ShruberryCreationForm(std::string target);
	~ShruberryCreationForm();
	ShruberryCreationForm(const ShruberryCreationForm &copy);
	ShruberryCreationForm &operator=(const ShruberryCreationForm &other);

	const std::string getTarget() const;

	void execute(Bureaucrat const & executor)const;
};

std::ostream &operator<<(std::ostream &out, const ShruberryCreationForm &f);