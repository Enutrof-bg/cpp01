#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	//albert signe et execute
	std::cout << "Test1" << std::endl;
	AForm* formA = NULL;
	try
	{
		Bureaucrat albert("albert", 1);
		Intern internA;
		
		formA = internA.makeForm("robotomy", "albert");
		if (formA)
		{
			albert.signForm(*formA);
			albert.executeForm(*formA);
			delete formA;
			formA = NULL;
			// throw AForm::GradeTooHighException();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete formA;
	}

	// bernard signe mais n'execeute pas
	std::cout << "\nTest2" << std::endl;
	AForm* formB = NULL;
	try
	{
		Bureaucrat bernard("bernard", 1);
		Intern internB;
		
		
		formB = internB.makeForm("presidential", "albert");
		if (formB)
		{
			bernard.signForm(*formB);
			bernard.executeForm(*formB);
			delete formB;
			formB = NULL;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete formB;
	}

	// // //charle ne peut pas signer et n'execute pas
	std::cout << "\nTest3" << std::endl;
	AForm* formC = NULL;
	try
	{
		Bureaucrat charle("charle", 1);
		Intern internC;
		
		formC = internC.makeForm("shrubbery", "albert");
		if (formC)
		{
			charle.signForm(*formC);
			charle.executeForm(*formC);
			delete formC;
			formC = NULL;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete formC;
	}

	//mauvais type de form
	std::cout << "\nTest4" << std::endl;
	AForm* formD = NULL;
	try
	{
		Bureaucrat charle("charle", 1);
		Intern internD;
		
		formD = internD.makeForm("shrubberyYY", "albert");
		charle.signForm(*formD);
		charle.executeForm(*formD);
		delete formD;
		formD = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete formD;
	}
	return (0);
}