#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackPoints = 20;
    std::cout << "ScavTrap Constructor Called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
    std::cout << "ScavTrap Copy Constructor Called!" <<  std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if(this != &other) {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap Copy Assignment Operator Called!" << std::endl;
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor Called!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (!energyPoints) {
        std::cout << "ScavTrap " << Name << " has no energy to attack!\n";
        return;
    }
    if (!hitPoints) {
        std::cout << "ScavTrap " << Name << " is dead and can't attack!\n";
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << Name << " attacks " << target 
              << ", causing " << attackPoints << " points of damage!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode.\n";
}
