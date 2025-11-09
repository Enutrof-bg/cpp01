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

AForm* createRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* createPresidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* createShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}


AForm* Intern::makeForm(std::string form, std::string target)
{
	AForm *newForm = NULL;

	AForm* (*formulaire[3])(std::string) = {&createPresidentialForm,
							&createRobotomyForm,
							&createShrubberyForm};
	std::string type[3] = {"presidential", "robotomy", "shrubbery"};

	for(int i = 0; i < 3; i++)
	{
		if (type[i] == form)
		{
			std::cout << "Intern creates " << form << " form." << std::endl;
			return (formulaire[i](target));
		}
	}
	std::cout << "Intern can't create " << form << " form." << std::endl;
	throw Intern::WrongType();
	return newForm;
}

const char* Intern::WrongType::what() const throw()
{
	return "Form's type is wrong.";
}