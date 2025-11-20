#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int minGrade, int minExecute)
		 : m_name(name),
		   m_signatureStatus(false),
		   m_minGrade(minGrade),
		   m_minExecute(minExecute)
{
	if (minGrade > 150 || minExecute > 150){
		std::cout << "GradeTooLowException called" << std::endl;
		throw Form::GradeTooLowException();
	} else if (minGrade < 1 || minExecute < 1) {
		std::cout << "GradeTooHighException called" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
}

Form::Form(const Form& other) 
	: m_name(other.m_name),
	  m_signatureStatus(other.m_signatureStatus),
	  m_minGrade(other.m_minGrade),
	  m_minExecute(other.m_minExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
		this->m_signatureStatus = other.m_signatureStatus;
    }
    return *this;
}

Form::~Form() {}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << std::endl
        << "Status: " << (form.getSignatureStatus() ? "Signed" : "Not Signed") << std::endl
        << "Grade to Sign: " << form.getMinGrade() << std::endl
        << "Grade to Execute: " << form.getMinExecute();
	return out;
}

const std::string Form::getName(void) const {
	return m_name;
}

bool Form::getSignatureStatus(void) const {
	return m_signatureStatus;
}

int Form::getMinGrade(void) const {
	return m_minGrade;
}

int Form::getMinExecute(void) const {
	return m_minExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	int grade = bureaucrat.getGrade();
	if (this->m_minGrade < grade){
		throw Form::GradeTooLowException();
	}
	this->m_signatureStatus = true;
}
