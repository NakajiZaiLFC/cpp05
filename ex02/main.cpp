#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        // Creating Bureaucrats
        std::cout << "=== Creating Bureaucrats ===" << std::endl;
        Bureaucrat intern("Rookie", 140);
        Bureaucrat executor("Executor", 40);
        Bureaucrat president("President", 1);

        std::cout << intern << std::endl;
        std::cout << executor << std::endl;
        std::cout << president << std::endl;

        // Creating Forms
        std::cout << "\n=== Creating Forms ===" << std::endl;
        ShrubberyCreationForm shrubbery("garden");
        RobotomyRequestForm robotomy("target");
        PresidentialPardonForm pardon("criminal");
		std::cout << std::endl;

        std::cout << shrubbery << std::endl;
		std::cout << std::endl;
        std::cout << robotomy << std::endl;
		std::cout << std::endl;
        std::cout << pardon << std::endl;
		std::cout << std::endl;

        // Signing Tests
        std::cout << "\n=== Signing Tests ===" << std::endl;

        // Intern signs Shrubbery Creation Form (Should succeed)
        intern.signForm(shrubbery);
		std::cout << std::endl;

        // Intern signs Robotomy Request Form (Should fail)
        intern.signForm(robotomy);
		std::cout << std::endl;

        // Executor signs Robotomy Request Form (Should succeed)
        executor.signForm(robotomy);
		std::cout << std::endl;

        // President signs Presidential Pardon Form (Should succeed)
        president.signForm(pardon);
		std::cout << std::endl;

        // Execution Tests
        std::cout << "\n=== Execution Tests ===" << std::endl;

        // Intern executes Shrubbery Creation Form (Should fail)
        intern.executeForm(shrubbery);
		std::cout << std::endl;

        // Executor executes Shrubbery Creation Form (Should succeed)
        executor.executeForm(shrubbery);
		std::cout << std::endl;

        // Executor executes Robotomy Request Form (Should succeed)
        executor.executeForm(robotomy);
		std::cout << std::endl;

        // Executor executes Presidential Pardon Form (Should fail)
        executor.executeForm(pardon);
		std::cout << std::endl;

        // President executes Presidential Pardon Form (Should succeed)
        president.executeForm(pardon);
		std::cout << std::endl;

        // Unsigned Form Execution Test
        std::cout << "\n=== Unsigned Form Execution Test ===" << std::endl;
        ShrubberyCreationForm unsignedForm("unsignedGarden");
        president.executeForm(unsignedForm);
    }
    catch (const std::exception &e)
    {
        std::cout << "An exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
