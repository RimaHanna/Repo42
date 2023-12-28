#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
    std::cout << "Sub class FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "Sub class FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "\033[33mFragTrap "<< this->name 
        << " High Five\033[0m" << std::endl;
}

// void FragTrap::attack(const std::string& target)
// {
//     if (this->energy_points == 0)
//     {
//         std::cout << "FragTrap is out of energy points" << std::endl;
//         return ;
//     }
//     std::cout << "FragTrap " << this->name 
//         << " attacks " << target <<", causing <amount>"
//              << " points of damage!"<< std::endl;
//     this->energy_points -= 1;
// }