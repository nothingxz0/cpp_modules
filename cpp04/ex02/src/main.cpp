#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    /*
        -- this line will result in a compilation error because Animal is now an abstract class --
        Absctract classes cannot be instantiated directly, they must be inherited by derived classes that implement the pure virtual functions.
    */
    // const Animal* meta = new Animal();
    Dog *j = new Dog();
    Cat *i = new Cat();
    std::cout << j->getType() << std::endl;
    j->makeSound();
    j->setIdea(0, "Dog idea 1");
    j->getIdea(0);
    std::cout << i->getType() << std::endl;
    i->makeSound();
    i->setIdea(0, "Cat idea 1");
    i->getIdea(0);
    delete j;
    delete i;
    return 0;
}