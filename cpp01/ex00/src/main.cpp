#include "Zombie.hpp"
#include <iostream>

int main() {
    Zombie* pp = newZombie("Foo");
    pp->announce();
    delete pp;
    randomChump("Soufiane");
}
