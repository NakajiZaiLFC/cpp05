#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int minGrade, int minExecute)
	: m_name(name),
	  m_signatureStatus(false),
	  m_minGrade(minGrade),
	  m_minExecute(minExecute)
{
	if (minGrade > 150 || minExecute > 150)
	{
		std::cout << "GradeTooLowException called" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else if (minGrade < 1 || minExecute < 1)
	{
		std::cout << "GradeTooHighException called" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
}

AForm::AForm(const AForm &other)
	: m_name(other.m_name),
	  m_signatureStatus(other.m_signatureStatus),
	  m_minGrade(other.m_minGrade),
	  m_minExecute(other.m_minExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->m_signatureStatus = other.m_signatureStatus;
	}
	return *this;
}

AForm::~AForm() {}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << "AForm: " << AForm.getName() << std::endl
		<< "Status: " << (AForm.getSignatureStatus() ? "Signed" : "Not Signed") << std::endl
		<< "Grade to Sign: " << AForm.getMinGrade() << std::endl
		<< "Grade to Execute: " << AForm.getMinExecute();
	return out;
}

const std::string AForm::getName(void) const
{
	return m_name;
}

bool AForm::getSignatureStatus(void) const
{
	return m_signatureStatus;
}

int AForm::getMinGrade(void) const
{
	return m_minGrade;
}

int AForm::getMinExecute(void) const
{
	return m_minExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	int grade = bureaucrat.getGrade();
	if (this->m_minGrade < grade)
	{
		throw AForm::GradeTooLowException();
	}
	this->m_signatureStatus = true;
}
