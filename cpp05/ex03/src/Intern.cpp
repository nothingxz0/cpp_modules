#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int index = -1;
    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
            index = i;
    }

    switch (index)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return (new ShrubberyCreationForm(target));
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return (new PresidentialPardonForm(target));
        default:
            std::cout << "Error: form \"" << formName << "\" does not exist" << std::endl;
            return (NULL);
    }
}