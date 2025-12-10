#include "Zombie.hpp"
#include <iostream>

int main() {
    Zombie* horde = zombieHorde(5, "soufiane");
    for (int i = 0; i < 5; i++) {
        horde[i].announce();
    }
    delete[] horde;
}
