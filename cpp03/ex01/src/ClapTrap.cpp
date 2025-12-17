#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name): Name(name), hitPoints(10), energyPoints(10), attackPoints(0) {
    std::cout << "ClapTrap instance Constructed with name: " << Name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): Name(other.Name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackPoints(other.attackPoints) {
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other){
        Name = other.Name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackPoints = other.attackPoints;
    }
    std::cout << "Copy assignement operator called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (!energyPoints) {
        std::cout << "ClapTrap " << Name << " has no energy to attack!\n";
        return;
    }
    if (!hitPoints) {
        std::cout << "ClapTrap " << Name << " is dead and can't attack!\n";
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << Name << " attacks " << target 
              << ", causing " << attackPoints << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << Name << " is already dead!\n";
        return;
    }

    if (amount >= hitPoints) {
        hitPoints = 0;
    }
    else 
        hitPoints -= amount;
    std::cout << "ClapTrap " << Name << " takes " << amount 
              << " points of damage! HP remaining: " << hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints == 0){
        std::cout << "ClapTrap " << Name << " has no energy to repair!\n";
        return;
    }
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << Name << " is already dead!\n";
        return;
    }
    energyPoints--;
    hitPoints += amount;
     std::cout << "ClapTrap " << Name << " repairs itself for " << amount 
              << " hit points! HP now: " << hitPoints << "\n";
}