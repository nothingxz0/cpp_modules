#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type): type(type){}
Weapon::~Weapon() {
    std::cout << "weapon destroyed" << std::endl;
}

std::string Weapon::getType() {
    return (type);
}

void        Weapon::setType(std::string type) {
    this->type = type;
}