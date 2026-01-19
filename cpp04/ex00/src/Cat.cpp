#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal(){
    type = "Cat";
    std::cout << "Cat Constructor Called." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){   
    std::cout << "Cat Copy Constructor Called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Cat Copy assignement operator Called." << std::endl;
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat Destructor Called." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meeeeeeeeow!" << std::endl;
}