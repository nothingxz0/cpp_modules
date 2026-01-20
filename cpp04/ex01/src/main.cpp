#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    Dog good;
    Dog goodd;
    Dog bad(good);
    good.setIdea(0, "Chase the cat");
    std::cout << "Good Dog Idea[0]: ";
    good.getIdea(0);
    std::cout << "Bad Dog Idea[0]: ";
    bad.getIdea(0);
    goodd = good;
    std::cout << "Goodd Dog Idea[0]: ";
    goodd.getIdea(0);
    bad = goodd;
    std::cout << "Bad Dog Idea[0] after assignement from Goodd: ";
    bad.getIdea(0);

    delete j;
    delete i;
    return 0;
}