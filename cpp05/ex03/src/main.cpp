#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL));

    std::cout << "\n===== 1. invalid form grades =====" << std::endl;
    try {
        ShrubberyCreationForm ok("garden");
        std::cout << ok << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== 2. execute UNSIGNED form =====" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm p("Arthur");
        boss.executeForm(p);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== 3. sign OK, execute grade too low =====" << std::endl;
    try {
        Bureaucrat mid("Mid", 20);
        PresidentialPardonForm p("Arthur");
        mid.signForm(p);
        mid.executeForm(p);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== 4. full success: PresidentialPardon =====" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm p("Arthur");
        boss.signForm(p);
        boss.executeForm(p);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== 5. full success: Robotomy x4 =====" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm r("Bender");
        boss.signForm(r);
        for (int i = 0; i < 4; i++)
            boss.executeForm(r);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== 6. full success: Shrubbery =====" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm s("home");
        boss.signForm(s);
        boss.executeForm(s);
        std::cout << "(check for a file named home_shrubbery)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== 7. boundary: grade exactly equal =====" << std::endl;
    try {
        Bureaucrat exact("Exact", 25);
        PresidentialPardonForm p("Ford");
        exact.signForm(p);        // needs 25, has 25 -> should sign
        exact.executeForm(p);     // needs 5, has 25  -> should fail
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== 8. sign grade too low =====" << std::endl;
    try {
        Bureaucrat low("Low", 150);
        PresidentialPardonForm p("Zaphod");
        low.signForm(p);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== 9. polymorphism through AForm* =====" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        AForm* forms[3];
        forms[0] = new ShrubberyCreationForm("yard");
        forms[1] = new RobotomyRequestForm("Marvin");
        forms[2] = new PresidentialPardonForm("Trillian");

        for (int i = 0; i < 3; i++) {
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
            delete forms[i];          // virtual dtor makes this correct
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== 10. bureaucrat exceptions =====" << std::endl;
    try {
        Bureaucrat bad("Bad", 0);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat bad("Bad", 151);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}