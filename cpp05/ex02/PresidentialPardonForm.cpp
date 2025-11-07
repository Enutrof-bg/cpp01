#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(Bureaucrat target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{

}


const std::string PresidentialPardonForm::getName() const
{
	return this->name;
}


bool PresidentialPardonForm::getIsSigned() const
{

}

int PresidentialPardonForm::getGradeToSign() const
{

}

int PresidentialPardonForm::getGradeToExec() const
{

}

const char * PresidentialPardonForm::GradeTooHighException::what() const throw()
{

}

const char * PresidentialPardonForm::GradeTooLowException::what() const throw()
{

}
