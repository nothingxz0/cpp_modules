#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
    FragTrap frag("Frag");
    ScavTrap scav("Scav");
    frag.attack("soufiane");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();

    scav.attack("nadaria");
    scav.takeDamage(15);
    scav.beRepaired(5);
    scav.guardGate();

    return 0;
}
