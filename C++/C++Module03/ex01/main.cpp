#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap Rima("Rima");
	ScavTrap Roy("Roy");

	std::cout << std::endl;

	Rima.attack("Roy");
	Roy.takeDamage(5);

	std::cout << std::endl;

	Rima.attack("Roy");
	Roy.takeDamage(1);

	Rima.attack("Roy");
	Roy.takeDamage(200);

	std::cout << std::endl;

	Roy.beRepaired(7);

	std::cout << std::endl;

	Rima.guardGate();
	Roy.guardGate();

	std::cout << std::endl;
    return 0;
}