#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
	try {
		Bureaucrat Tom("Tom", 3);
		std::cout << Tom << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat Jack("Jack", 0);
		std::cout << Jack << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat Jack("Kyle", 1000);
		std::cout << Jack << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
