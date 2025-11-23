#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target);

		class FormDoesntExistException : public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Form name does not exist";
				}
		};
	private:
		static const int formKindNum = 3;
		AForm* createShrubbery(const std::string& target);
		AForm* createRobotomy(const std::string& target);
		AForm* createPresidential(const std::string& target);
};

