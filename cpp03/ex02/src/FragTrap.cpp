#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackPoints = 30;
    std::cout << "FragTrap Constructor Called with name: " << Name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
    std::cout << "FragTrap Copy Constructor Called!" <<  std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if(this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap Copy Assignment Operator Called!" << std::endl;
    }
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor Called!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (!energyPoints) {
        std::cout << "FragTrap " << Name << " has no energy to attack!\n";
        return;
    }
    if (!hitPoints) {
        std::cout << "FragTrap " << Name << " is dead and can't attack!\n";
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << Name << " attacks " << target 
              << ", causing " << attackPoints << " points of damage!\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << Name << " is requesting a high five! ✋\n";
}