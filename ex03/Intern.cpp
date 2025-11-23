#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	const std::string formsList[formKindNum] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*fromCreators[formKindNum])(const std::string&) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};	

	for (int i = 0; i < formKindNum; i++){
		if (formName == formsList[i]){
			std::cout << "Intern creates " << formsList[i] << std::endl;
			return (this->*fromCreators[i])(target);
		}
	}
	std::cout << "Intern cannot create " << formName << " (unknown form)" << std::endl;
    throw FormDoesntExistException();
}

AForm* Intern::createShrubbery(const std::string& target){
	return new ShrubberyCreationForm(target);
}


AForm* Intern::createRobotomy(const std::string& target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target){
	return new PresidentialPardonForm(target);
}
