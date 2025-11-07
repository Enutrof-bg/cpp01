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

	// try
	// {
	// 	if (form == "robotomy")
	// 		newForm = new RobotomyRequestForm(target);
	// 	else if (form == "presidential")
	// 		newForm = new PresidentialPardonForm(target);
	// 	else if (form == "shruberry")
	// 		newForm = new ShruberryCreationForm(target);
	// 	std::cout << "Intern creates " << form << " form." << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "Error" << std::endl;
	// }

	if (form == "robotomy")
		newForm = new RobotomyRequestForm(target);
	else if (form == "presidential")
		newForm = new PresidentialPardonForm(target);
	else if (form == "shruberry")
		newForm = new ShruberryCreationForm(target);
	else
	{
		std::cout << "Error" << std::endl;
		return newForm;
	}
	std::cout << "Intern creates " << form << " form." << std::endl;

	return newForm;
}