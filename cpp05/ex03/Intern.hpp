#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &other);

	AForm *makeForm(std::string form, std::string target);
};