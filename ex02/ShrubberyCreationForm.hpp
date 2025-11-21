#pragma once
#include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
	virtual void execute(const Bureaucrat &bureaucrat) const;
	bool treePlanting(void) const;

private:
    ShrubberyCreationForm();
	std::string m_target;
};
