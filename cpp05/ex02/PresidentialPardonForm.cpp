#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5), target("Default bob")
{

}

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

const std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == 0)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowExecException();
	else
	{
		std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox."<<std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &f)
{
	out << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< ", Grade Required to Sign: " << f.getGradeToSign()
		<< ", Grade Required to Execute: " << f.getGradeToExec()
		<< ", Target: " << f.getTarget() << std::endl;
	return (out);
}