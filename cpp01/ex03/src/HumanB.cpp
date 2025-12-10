#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): name(name) {}
HumanB::~HumanB() {}

void    HumanB::attack() {
    std::cout << name << " attacks with their " << weaponB->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& weaponB) {
    this->weaponB = &weaponB;
}