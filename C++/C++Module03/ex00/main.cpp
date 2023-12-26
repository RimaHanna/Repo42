#include "ClapTrap.hpp"
#include <iostream>


int main()
{
    ClapTrap attacker("Rima");
    ClapTrap counterAttacker("Roy");

    std::cout << std::endl;

    attacker.attack("Roy");
    counterAttacker.takeDamage(5);
    
    std::cout << std::endl;

    attacker.attack("Roy");
    counterAttacker.takeDamage(5);

    std::cout << std::endl;

    counterAttacker.beRepaired(5);
    counterAttacker.beRepaired(5);
    counterAttacker.beRepaired(5);
    counterAttacker.beRepaired(5);
    counterAttacker.beRepaired(5);
    counterAttacker.beRepaired(5);
    counterAttacker.beRepaired(5);
    counterAttacker.beRepaired(5);
    counterAttacker.beRepaired(5);
    counterAttacker.beRepaired(5);
    counterAttacker.beRepaired(5);
    
    std::cout << std::endl;
    return 0;
}