#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
	try {
		Bureaucrat Tom("Tom", 1);
		std::cout << Tom << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat Tom("Mike", 149);
		std::cout << Tom << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat Jack("Jack", 0);
		std::cout << Jack << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat Jack("Kyle", 1000);
		std::cout << Jack << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
