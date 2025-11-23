#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("presidential pardon", 25, 5), m_target(target){
    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), m_target(other.m_target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
		this->m_target = other.m_target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}


void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	int grade = bureaucrat.getGrade();

	if (!getSignatureStatus())
		throw AForm::FormNotSignedException();
	else if (grade > this->getMinExecute())
		throw AForm::GradeTooLowException();
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
