#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	//albert signe et execute
	std::cout << "Test1" << std::endl;
	try
	{
		Bureaucrat albert("albert", 1);
		Intern internA;
		AForm* formA;
		
		formA = internA.makeForm("robotomy", "albert");;
		albert.signForm(*formA);
		albert.executeForm(*formA);

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//bernard signe mais n'execeute pas
	std::cout << "\nTest2" << std::endl;
	try
	{
		Bureaucrat bernard("bernard", 1);
		Intern internB;
		AForm* formB;
		
		formB = internB.makeForm("presidential", "albert");;
		bernard.signForm(*formB);
		bernard.executeForm(*formB);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// //charle ne peut pas signer et n'execute pas
	std::cout << "\nTest3" << std::endl;
	try
	{
		Bureaucrat charle("charle", 1);
		Intern internC;
		AForm* formC;
		
		formC = internC.makeForm("shrubbery", "albert");;
		charle.signForm(*formC);
		charle.executeForm(*formC);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//mauvais type de form
	std::cout << "\nTest4" << std::endl;
	try
	{
		Bureaucrat charle("charle", 1);
		Intern internD;
		AForm* formD;
		
		formD = internD.makeForm("shrubberyYY", "albert");;
		charle.signForm(*formD);
		charle.executeForm(*formD);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}