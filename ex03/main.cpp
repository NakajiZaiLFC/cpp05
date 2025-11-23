#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    // =================================================================================
    // TEST 0: Bureaucrat Validation (Creating Invalid Bureaucrats)
    // =================================================================================
    std::cout << "========================================" << std::endl;
    std::cout << " TEST 0: Bureaucrat Validation" << std::endl;
    std::cout << "========================================" << std::endl;
    try {
        std::cout << ">> Action: Creating a Bureaucrat with grade 0." << std::endl;
        std::cout << ">> Expected: Exception caught (Grade too high)." << std::endl;
        Bureaucrat tooHigh("God", 0);
    } catch (const std::exception& e) {
        std::cout << "Result: Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // =================================================================================
    // MAIN TESTS: Intern, Forms, and Permissions
    // =================================================================================
    
    // Initialize pointers to NULL for safety
    AForm *shrub = NULL;
    AForm *robot = NULL;
    AForm *pardon = NULL;

    try
    {
        std::cout << "========================================" << std::endl;
        std::cout << " SETUP: Creating Actors and Forms" << std::endl;
        std::cout << "========================================" << std::endl;

        Intern someRandomIntern;
        
        // 1. CEO (Grade 1) - Can do everything
        Bureaucrat ceo("CEO", 1);
        // 2. Senior (Grade 50) - Can Sign Robotomy (72), but CANNOT Exec Robotomy (45)
        Bureaucrat senior("Senior", 50);
        // 3. Newbie (Grade 150) - Cannot do anything
        Bureaucrat newbie("Newbie", 150);

        std::cout << ceo << std::endl;
        std::cout << senior << std::endl;
        std::cout << newbie << std::endl;
        std::cout << std::endl;

        // Creating Forms via Intern
        std::cout << ">> Action: Intern creates 3 forms." << std::endl;
        shrub = someRandomIntern.makeForm("shrubbery creation", "Garden");
        robot = someRandomIntern.makeForm("robotomy request", "Bender");
        pardon = someRandomIntern.makeForm("presidential pardon", "Criminal");
        std::cout << std::endl;


        // =================================================================================
        // CASE 1 & 2: Signing Permissions
        // =================================================================================
        std::cout << "========================================" << std::endl;
        std::cout << " CASE 1 & 2: Signing Permissions" << std::endl;
        std::cout << "========================================" << std::endl;
        
        // CASE 1: Sign without permission
        std::cout << "[Test: Newbie tries to sign Shrubbery (Req: 145)]" << std::endl;
        std::cout << ">> Expected: Newbie couldn't sign ... Grade is too low." << std::endl;
        newbie.signForm(*shrub);
        std::cout << std::endl;

        // CASE 2: Sign with permission
        std::cout << "[Test: Senior tries to sign Shrubbery (Req: 145)]" << std::endl;
        std::cout << ">> Expected: Senior signed shrubbery creation." << std::endl;
        senior.signForm(*shrub); // Senior(50) <= 145 -> OK
        std::cout << std::endl;


        // =================================================================================
        // CASE 3: Execute without signed permission
        // =================================================================================
        std::cout << "========================================" << std::endl;
        std::cout << " CASE 3: Execute Unsigned Form" << std::endl;
        std::cout << "========================================" << std::endl;

        // Robotomy is currently unsigned
        std::cout << "[Test: CEO tries to execute Robotomy (Not Signed yet)]" << std::endl;
        std::cout << ">> Expected: CEO couldn't execute ... Form is not signed." << std::endl;
        ceo.executeForm(*robot);
        std::cout << std::endl;


        // =================================================================================
        // CASE 4: Sign OK, but Exec NG
        // =================================================================================
        std::cout << "========================================" << std::endl;
        std::cout << " CASE 4: Sign OK, Execute NG" << std::endl;
        std::cout << "========================================" << std::endl;

        // Target: Robotomy (Sign: 72, Exec: 45)
        // Actor: Senior (Grade 50)
        
        // 1. Signing
        std::cout << "[Step 1: Senior signs Robotomy (50 <= 72)]" << std::endl;
        std::cout << ">> Expected: Senior signed robotomy request." << std::endl;
        senior.signForm(*robot);
        std::cout << std::endl;

        // 2. Executing (Failure expected)
        std::cout << "[Step 2: Senior executes Robotomy (50 > 45)]" << std::endl;
        std::cout << ">> Expected: Senior couldn't execute ... Grade is too low." << std::endl;
        senior.executeForm(*robot);
        std::cout << std::endl;


        // =================================================================================
        // CASE 5: Full Permission Execution
        // =================================================================================
        std::cout << "========================================" << std::endl;
        std::cout << " CASE 5: Full Permission Execution" << std::endl;
        std::cout << "========================================" << std::endl;

        // 1. Robotomy (Signed by Senior, Executed by CEO)
        std::cout << "[Test: CEO executes Robotomy]" << std::endl;
        std::cout << ">> Expected: Drilling noises... then success/fail message." << std::endl;
        std::cout << ">> Expected: CEO executed robotomy request." << std::endl;
        ceo.executeForm(*robot);
        std::cout << std::endl;

        // 2. Presidential Pardon (Sign: 25, Exec: 5)
        // Senior cannot sign this (50 > 25), so CEO must do it.
        std::cout << "[Test: CEO signs and executes Pardon]" << std::endl;
        std::cout << ">> Expected: CEO signed... then Zaphod Beeblebrox message... then CEO executed." << std::endl;
        ceo.signForm(*pardon);
        ceo.executeForm(*pardon);
        std::cout << std::endl;


        // =================================================================================
        // CASE 6: Intern Error (Non-existent Form)
        // =================================================================================
        std::cout << "========================================" << std::endl;
        std::cout << " CASE 6: Intern Error (Exception Test)" << std::endl;
        std::cout << "========================================" << std::endl;

        std::cout << ">> Action: Intern tries to create 'Tax Evasion Form'." << std::endl;
        std::cout << ">> Expected: Intern cannot create... (unknown form)" << std::endl;
        std::cout << ">> Expected: Exception caught and memory cleaned up." << std::endl;

        // This will throw an exception, jumping to catch block
        AForm *fake = someRandomIntern.makeForm("Tax Evasion Form", "Me");
        (void)fake; 

        delete shrub;
        delete robot;
        delete pardon;
    }
    catch (const std::exception &e)
    {
        std::cout << "Result: Exception caught: " << e.what() << std::endl;
        
        std::cout << "\n>> Cleaning up memory in catch block..." << std::endl;
        if (shrub != NULL) { delete shrub; std::cout << "- shrub deleted" << std::endl; }
        if (robot != NULL) { delete robot; std::cout << "- robot deleted" << std::endl; }
        if (pardon != NULL) { delete pardon; std::cout << "- pardon deleted" << std::endl; }
    }

    return 0;
}
