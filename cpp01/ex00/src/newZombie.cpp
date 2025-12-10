#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie* placeholder = new Zombie(name);
    return (placeholder);
}