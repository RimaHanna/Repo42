#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage  = 0;
    std::cout << "ClapTrap constructor " << name << " called"<< std::endl;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called " << std::endl;
    return ;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &copy)
{
    this->name = copy.name;
    this->hit_points = copy.hit_points;
    this->energy_points = copy.energy_points;
    this->attack_damage  =copy.attack_damage;
    std::cout << "ClapTrap copy constructor called" << std::endl;
    return ;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
    // avoid self assignment
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage  =other.attack_damage;
        std::cout << "ClapTrap copy assignment called" << std::endl;
    }
    return *this;
}


void ClapTrap::attack(const std::string& target)
{
    if (this->energy_points == 0)
    {
        std::cout << "ClapTrap is out of energy points" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name 
        << " attacks " << target <<", causing <amount>"
             << " points of damage!"<< std::endl;
    this->energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= this->hit_points || this->hit_points == 0)
    {
        std::cout << "\033[31mTrapCrap " << this->name << " died!\033[0m" << std::endl;
        this->hit_points = 0;
        return ;
    }
    std::cout << "ClapTrap "<< this->name 
        << " was attacked " << amount 
            << " of points" << std::endl;
    this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_points == 0)
    {
		std::cout << "ClapTrap is out of energy points!" << std::endl;
		return ;
    }
    this->hit_points += amount;
    this->energy_points -= 1;
    std::cout << "TrapCrap " << this->name
        << " received " << amount << " points of energy!" << std::endl;
}