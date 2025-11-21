#pragma once
#include "AForm.hpp"
class RobotomyRequestForm : public AForm{
public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
	virtual void execute(const Bureaucrat &bureaucrat) const;

private:
    RobotomyRequestForm();
	std::string m_target;
};

