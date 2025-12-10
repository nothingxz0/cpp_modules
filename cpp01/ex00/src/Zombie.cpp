#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string n): name(n){} 
Zombie::~Zombie() {
    std::cout << name << std::endl;
}

void    Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}