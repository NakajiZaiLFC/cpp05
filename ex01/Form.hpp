#pragma once
#include <iostream>

class Bureaucrat;

class Form {
public:
	/**
	 * OCF
	 */
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

	/**
	 * Member Function
	 */
	Form(const std::string& name, int minGrade, int minExecute);
	void beSigned(const Bureaucrat& bureaucrat);
	const std::string getName(void) const;
	bool getSignatureStatus(void) const;
	int getMinGrade(void) const;
	int getMinExecute(void) const;


	/**
	 * Exception Class
	 */
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw(){
				return "";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw(){
				return "";
			}
	};

private:
    Form();
    const std::string m_name;
	bool m_signatureStatus;
	const int m_minGrade;
	const int m_minExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& form);