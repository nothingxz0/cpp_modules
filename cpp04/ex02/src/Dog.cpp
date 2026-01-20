#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal() {
    this->type = "Dog";
    brain = new Brain();
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->type = other.type;
        *this->brain = *other.brain;
    }
    std::cout << "Dog Copy assignement operator called" << std::endl;
    return (*this);
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Wooooooof!" << std::endl;
}


void	Dog::getIdea(size_t i) const
{
	std::cout << this->brain->getIdea(i) << std::endl;
}

void	Dog::setIdea(size_t i, std::string idea)
{
		this->brain->setIdea(i, idea);
}