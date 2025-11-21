#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("ROBOT", 72, 45), m_target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const 
{
	int grade = bureaucrat.getGrade();

	if (!getSignatureStatus())
		throw AForm::FormNotSignedException();
	else if (grade > this->getMinExecute())
		throw AForm::GradeTooLowException();
	std::cout << "Drilling noises... Bzzzzzt!" << std::endl;
	if (std::rand() % 2){
		std::cout << m_target << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << "robotomy failed" << std::endl;
	}
}

