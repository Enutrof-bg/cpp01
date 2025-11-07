#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	AForm *newForm = NULL;
	if (form == "robotomy")
	{
		newForm = new RobotomyRequestForm(target);
		// newForm = tmp;
	}
	else if (form == "presidential")
	{
		newForm = new PresidentialPardonForm(target);
		// newForm = tmp;
	}
	else if (form == "shruberry")
	{
		newForm = new ShruberryCreationForm(target);
		// newForm = tmp;
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
	std::cout << "Intern creates " << form << " form." << std::endl;
	return newForm;
}