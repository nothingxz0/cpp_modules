#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b1("Alice", 42);
        Form f1("Form1", 42, 50);
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 1);
        Form f2("Form2", 0, 50);
        b2.signForm(f2);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 150);
        Form f3("Form3", 151, 50);
        b3.signForm(f3);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("David", 1);
        b4.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Eve", 150);
        b5.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b6("Frank", 42);
        Form f6("Form6", 42, 50);
        b6.signForm(f6);
        std::cout << f6 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b1("Alice", 52);
        Form f7("Form7", 42, 50);
        b1.signForm(f7);
        std::cout << f7 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}