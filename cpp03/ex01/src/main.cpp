#include "ScavTrap.hpp"


int main() {
    ScavTrap scav("Guardian");
    ScavTrap scavCopy(scav);

    scav.attack("Intruder");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
}