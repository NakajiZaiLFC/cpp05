#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
public:
	/**
	 * OCF
	 */
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	/**
	 * Member Function
	 */
	AForm(const std::string &name, int minGrade, int minExecute);
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &bureaucrat) const = 0;
	const std::string getName(void) const;
	bool getSignatureStatus(void) const;
	int getMinGrade(void) const;
	int getMinExecute(void) const;

	/**
	 * Exception Class
	 */
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Grade is too low!";
		}
	};

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Form is not signed!";
		}
	};

private:
	AForm();
	const std::string m_name;
	bool m_signatureStatus;
	const int m_minGrade;
	const int m_minExecute;
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);
