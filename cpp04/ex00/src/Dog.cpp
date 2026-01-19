#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal() {
    this->type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Dog Copy assignement operator called" << std::endl;
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Wooooooof!" << std::endl;
}