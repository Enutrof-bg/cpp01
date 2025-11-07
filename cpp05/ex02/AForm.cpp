#include "AForm.hpp"

AForm::AForm() : name("Default"), is_signed(false), grade_to_sign(150), grade_to_exec(150)
{
}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_exec) : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
}
AForm::~AForm()
{
}

AForm::AForm(const AForm &copy):name(copy.name), is_signed(copy.is_signed), 
		grade_to_sign(copy.grade_to_sign), grade_to_exec(copy.grade_to_exec)
{

}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return (*this);
}

const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->is_signed);
}

int AForm::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int AForm::getGradeToExec() const
{
	return (this->grade_to_exec);
}

// void AForm::beSigned(Bureaucrat buro)
// {
// 	if (buro.getGrade() > this->grade_to_sign)
// 		throw AForm::GradeTooLowException();
// 	else
// 		this->is_signed = true;
// }

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high for Aform");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low for Aform");
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< ", Grade Required to Sign: " << f.getGradeToSign()
		<< ", Grade Required to Execute: " << f.getGradeToExec();
	return (out);
}