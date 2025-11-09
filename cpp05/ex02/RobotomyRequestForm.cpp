#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45), target("Default bob")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		// this->target = other.target;
		this->is_signed = other.is_signed;
	}
	return *this;
}

const std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == 0)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowExecException();
	else
	{
		std::cout << "BRBRBRBRBRBRBRBRBRBR..." << std::endl;
		std::srand(std::time(0));
		int random = rand();
		if (random % 2 == 0)
		{
			std::cout << this->getTarget() << " has been robotomized." << std::endl;
		}
		else 
		{
			std::cout << "Robotomize has failed. :(" << std::endl;
		}
	}
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &f)
{
	out << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< ", Grade Required to Sign: " << f.getGradeToSign()
		<< ", Grade Required to Execute: " << f.getGradeToExec()
		<< ", Target: " << f.getTarget() << std::endl;
	return (out);
}