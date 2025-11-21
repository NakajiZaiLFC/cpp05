#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("TREE", 145, 137), m_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

bool ShrubberyCreationForm::treePlanting(void) const
{
	std::string filename = this->m_target + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (!ofs)
		return false;
	ofs << "       _-_        " << std::endl;
	ofs << "    /~~   ~~\\    " << std::endl;
	ofs << " /~~         ~~\\ " << std::endl;
	ofs << "{               } " << std::endl;
	ofs << " \\  _-     -_  / " << std::endl;
	ofs << "   ~  \\\\ //  ~  " << std::endl;
	ofs << "_- -   | | _- _   " << std::endl;
	ofs << "  _ -  | |   -_   " << std::endl;
	ofs << "      // \\\\      " << std::endl;
	ofs << std::endl;
	ofs.close();
	std::cout << "Created shrubbery file: " << filename << std::endl;
	return true;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	int grade = bureaucrat.getGrade();

	if (!getSignatureStatus())
		throw AForm::FormNotSignedException();
	else if (grade > this->getMinExecute())
		throw AForm::GradeTooLowException();
	if (!treePlanting())
	{
		std::cerr << "Error: can't tree planting at " << m_target << std::endl;
	}
}
