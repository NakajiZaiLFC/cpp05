#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--- Form Construction Test ---" << std::endl;
    try {
        Form invalid("InvalidForm", 0, 50);
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Signing Test ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        
        Form formA("Tax Form", 40, 100);
        Form formB("Lunch Form", 60, 100);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        std::cout << "\n[Attempt 1]" << std::endl;
        bob.signForm(formA);
        std::cout << "Form A status: " << (formA.getSignatureStatus() ? "Signed" : "Not Signed") << std::endl;

        std::cout << "\n[Attempt 2]" << std::endl;
        bob.signForm(formB);
        std::cout << "Form B status: " << (formB.getSignatureStatus() ? "Signed" : "Not Signed") << std::endl;

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
