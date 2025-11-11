#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Request Form", 145, 137), target("Default bob")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Request Form", 145, 137), target(target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		// this->target = other.target;
		this->is_signed = other.is_signed;
	}
	return *this;
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
		if (!output.is_open())
			throw AForm::OpenFailed();

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

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &f)
{
	out << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< ", Grade Required to Sign: " << f.getGradeToSign()
		<< ", Grade Required to Execute: " << f.getGradeToExec()
		<< ", Target: " << f.getTarget() << std::endl;
	return (out);
}