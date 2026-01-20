#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    for (int i = 0; i < 100; i++) {
        ideas[i] = "";
    }
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

const std::string	Brain::getIdea(size_t i) const {
	if (i < 100)
		return(this->ideas[i]);
	return ("Only 100 ideas per brain.");
}

void	Brain::setIdea(size_t i, std::string idea)
{
	if (i < 100)
		this->ideas[i] = idea;
	else
		std::cout << "Only 100 ideas per brain." << std::endl;
}