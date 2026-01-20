#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal(){
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat Constructor Called." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){   
    brain = new Brain(*other.brain);
    std::cout << "Cat Copy Constructor Called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->type = other.type;
        *this->brain = *other.brain;
    }
    std::cout << "Cat Copy assignement operator Called." << std::endl;
    return (*this);
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat Destructor Called." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meeeeeeeeow!" << std::endl;
}

void	Cat::getIdea(size_t i) const
{
	std::cout << this->brain->getIdea(i) << std::endl;
}

void	Cat::setIdea(size_t i, std::string idea)
{
		this->brain->setIdea(i, idea);
}