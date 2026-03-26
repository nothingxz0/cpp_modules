#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob.getName() << ", grade: " << bob.getGrade() << std::endl;

        bob.incrementGrade();
        std::cout << "After increment: " << bob.getName() << ", grade: " << bob.getGrade() << std::endl;

        bob.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}