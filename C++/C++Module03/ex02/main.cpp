#include "FragTrap.hpp"
#include <iostream>


int main()
{
	FragTrap Rima("Rima");
	FragTrap Roy("Roy");

	std::cout << std::endl;

	Rima.attack("Roy");
	Roy.takeDamage(30);

	std::cout << std::endl;

	Rima.attack("Roy");
	Roy.takeDamage(30);

	std::cout << std::endl;

	Rima.attack("Roy");
	Roy.takeDamage(30);

	std::cout << std::endl;

	Rima.attack("Roy");
	Roy.takeDamage(30);

	std::cout << std::endl;

	Roy.beRepaired(100);

	std::cout << std::endl;

	Roy.highFivesGuys();

	std::cout << std::endl;

	Roy.takeDamage(100);

    return 0;
}