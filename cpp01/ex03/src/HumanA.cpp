#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weaponA): weaponA(weaponA){
    this->name = name;
}

HumanA::~HumanA() {}

void   HumanA::attack() {
    std::cout << name << " attacks with their " << weaponA.getType() << std::endl;
}