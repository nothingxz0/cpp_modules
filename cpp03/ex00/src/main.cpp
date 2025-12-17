#include "ClapTrap.hpp"
#include <iostream>


int main() {
    ClapTrap trap("Soufiane");
    ClapTrap clap(trap);

    trap.attack("hello");
    trap.takeDamage(20);
    trap.attack("hello");
}
