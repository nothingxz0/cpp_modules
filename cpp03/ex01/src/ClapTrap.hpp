#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

typedef struct playerPosition
{
    int x;
    int y;
    int z;
} playerPosition;


class ClapTrap {
    protected:
        std::string Name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackPoints;
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif