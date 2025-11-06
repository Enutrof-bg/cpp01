#include "Form.hpp"

Form::Form() : name("Default"), is_signed(false), grade_to_sign(150), grade_to_exec(150)
{
}

Form::Form(const std::string &name, int grade_to_sign, int grade_to_exec) : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
}
Form::~Form()
{
}

Form::Form(const Form &copy):name(copy.name), is_signed(copy.is_signed), 
		grade_to_sign(copy.grade_to_sign), grade_to_exec(copy.grade_to_exec)
{

}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->is_signed = other.is_signed;
	}
	return (*this);
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->is_signed);
}

int Form::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int Form::getGradeToExec() const
{
	return (this->grade_to_exec);
}

void Form::beSigned(Bureaucrat buro)
{
	if (buro.getGrade() > this->grade_to_sign)
		throw Form::GradeTooLowException();
	else
		this->is_signed = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high for form");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low for form");
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< ", Grade Required to Sign: " << f.getGradeToSign()
		<< ", Grade Required to Execute: " << f.getGradeToExec();
	return (out);
}