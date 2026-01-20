#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type("Unknown") {
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal& other): type(other.type) {
    std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {  
        this->type = other.type;
    }
    std::cout << "Animal Copy assignement operator called" << std::endl;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}


std::string Animal::getType() const {
    return (type);
}