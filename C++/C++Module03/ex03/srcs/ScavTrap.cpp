#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
    std::cout << "Sub class ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Sub class ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "\033[33mScavTrap "<< this->name 
        << " is now in Gate keeper mode\033[0m" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energy_points == 0)
    {
        std::cout << "Scavtrap is out of energy points" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name 
        << " attacks " << target <<", causing <amount>"
             << " points of damage!"<< std::endl;
    this->energy_points -= 1;
}