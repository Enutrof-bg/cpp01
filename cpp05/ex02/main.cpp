#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	//albert signe et execute
	std::cout << "Test1" << std::endl;
	try
	{
		Bureaucrat albert("albert", 2);
		PresidentialPardonForm formA("albert");
		albert.signForm(formA);
		albert.executeForm(formA);
		std::cout << albert << std::endl;
		std::cout << formA << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//bernard signe mais n'execeute pas
	std::cout << "\nTest2" << std::endl;
	try
	{
		Bureaucrat bernard("bernard", 20);
		PresidentialPardonForm formB("bernard");
		bernard.signForm(formB);
		bernard.executeForm(formB);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//charle ne peut pas signer et n'execute pas
	std::cout << "\nTest3" << std::endl;
	try
	{
		Bureaucrat charle("charle", 30);
		PresidentialPardonForm formC("charle");
		charle.signForm(formC);
		charle.executeForm(formC);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//david ne peut pas signer
	std::cout << "\nTest5" << std::endl;
	try
	{
		Bureaucrat david("david", 80);
		RobotomyRequestForm formD("david");
		david.signForm(formD);
		david.executeForm(formD);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//eric ne peut pas exec
	std::cout << "\nTest6" << std::endl;
	try
	{
		Bureaucrat eric("eric", 50);
		RobotomyRequestForm formE("eric");
		eric.signForm(formE);
		eric.executeForm(formE);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//fred signe et exec
	std::cout << "\nTest6" << std::endl;
	try
	{
		Bureaucrat fred("fred", 30);
		RobotomyRequestForm formF("fred");
		fred.signForm(formF);
		fred.executeForm(formF);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//gerard ne peut pas signer
	std::cout << "\nTest7" << std::endl;
	try
	{
		Bureaucrat gerard("gerard", 146);
		ShrubberyCreationForm formG("gerard");
		gerard.signForm(formG);
		gerard.executeForm(formG);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//triple h signe mais n'exec pas
	std::cout << "\nTest8" << std::endl;
	try
	{
		Bureaucrat hhh("hhh", 145);
		ShrubberyCreationForm formH("hhh");
		hhh.signForm(formH);
		hhh.executeForm(formH);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//iric signe et exec
	std::cout << "\nTest9" << std::endl;
	try{
		Bureaucrat iric("iric", 137);
		ShrubberyCreationForm formI("iric");
		iric.signForm(formI);
		iric.executeForm(formI);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTest10" << std::endl;
	try
	{
		Bureaucrat test1("test1", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat test2("test2", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
}