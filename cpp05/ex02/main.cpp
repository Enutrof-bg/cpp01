#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

int main()
{
	std::cout << "Test1" << std::endl;
	Bureaucrat albert("albert", 2);
	PresidentialPardonForm formA("albert");
	albert.signForm(formA);
	albert.executeForm(formA);
	std::cout << albert << std::endl;
	std::cout << formA << std::endl;

	std::cout << "\nTest2" << std::endl;
	Bureaucrat bernard("bernard", 20);
	PresidentialPardonForm formB("bernard");
	bernard.signForm(formB);
	bernard.executeForm(formB);

	std::cout << "\nTest3" << std::endl;
	Bureaucrat charle("charle", 30);
	PresidentialPardonForm formC("charle");
	charle.signForm(formC);
	charle.executeForm(formC);
}