#pragma once
#include "AForm.hpp"
class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
	virtual void execute(const Bureaucrat &bureaucrat) const;

private:
    PresidentialPardonForm();
	std::string m_target;
};

