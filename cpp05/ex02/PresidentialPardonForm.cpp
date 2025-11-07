#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		// this->target = other.target;
		this->is_signed = other.is_signed;
	}
	return *this;
}

const std::string PresidentialPardonForm::getName() const
{
	return this->name;
}

bool PresidentialPardonForm::getIsSigned() const
{
	return this->is_signed;
}

int PresidentialPardonForm::getGradeToSign() const
{
	return this->grade_to_sign;
}

int PresidentialPardonForm::getGradeToExec() const
{
	return this->grade_to_exec;
}

const std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == 0)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox."<<std::endl;
	}
}

const char * PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return "Erreur : grade too low for presidential pardon";
}

const char * PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return "Erreur : grade too high for presidential pardon";
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &f)
{
	out << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< ", Grade Required to Sign: " << f.getGradeToSign()
		<< ", Grade Required to Execute: " << f.getGradeToExec()
		<< ", Target: " << f.getTarget() << std::endl;
	return (out);
}