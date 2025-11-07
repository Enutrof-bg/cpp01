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
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	const std::string getTarget() const;

	void execute(Bureaucrat const & executor)const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &f);