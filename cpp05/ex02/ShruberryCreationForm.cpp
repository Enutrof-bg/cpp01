#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(std::string target): AForm("Shruberry Request Form", 145, 137), target(target)
{

}

ShruberryCreationForm::~ShruberryCreationForm()
{

}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &copy)
{
	*this = copy;
}

ShruberryCreationForm &ShruberryCreationForm::operator=(const ShruberryCreationForm &other)
{
	if (this != &other)
	{
		// this->target = other.target;
		this->is_signed = other.is_signed;
	}
	return *this;
}

// const std::string ShruberryCreationForm::getName() const
// {
// 	return this->name;
// }

// bool ShruberryCreationForm::getIsSigned() const
// {
// 	return this->is_signed;
// }

// int ShruberryCreationForm::getGradeToSign() const
// {
// 	return this->grade_to_sign;
// }

// int ShruberryCreationForm::getGradeToExec() const
// {
// 	return this->grade_to_exec;
// }

const std::string ShruberryCreationForm::getTarget() const
{
	return this->target;
}

void ShruberryCreationForm::execute(Bureaucrat const & executor) const
{
	std::string filename;
	std::ofstream output;
	std::string text;
	
	if (this->getIsSigned() == 0)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowExecException();
	else
	{
		filename = this->getTarget() + "_shrubbery";
		output.open(filename.c_str());

		text =  "   oxoxoo    ooxoo\n"
				"  ooxoxo oo  oxoxooo\n"
				" oooo xxoxoo ooo ooox\n"
				" oxo o oxoxo  xoxxoxo\n"
				"  oxo xooxoooo o ooo\n"
				"    ooo\\oo\\  /o/o\n"
				"        \\  \\/ /\n"
				"         |   /\n"
				"         |  |\n"
				"         | D|\n"
				"         |  |\n"
				"         |  |\n"
				"  ______/____\\____";
		output << text << std::endl;

		output.close();
	}
}

// const char * ShruberryCreationForm::GradeTooHighException::what() const throw()
// {
// 	return "Erreur : grade too low for presidential pardon";
// }

// const char * ShruberryCreationForm::GradeTooLowException::what() const throw()
// {
// 	return "Erreur : grade too high for presidential pardon";
// }

std::ostream &operator<<(std::ostream &out, const ShruberryCreationForm &f)
{
	out << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< ", Grade Required to Sign: " << f.getGradeToSign()
		<< ", Grade Required to Execute: " << f.getGradeToExec()
		<< ", Target: " << f.getTarget() << std::endl;
	return (out);
}