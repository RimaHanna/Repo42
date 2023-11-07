#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& humanName, Weapon& humanWeapon) : name(humanName), weapon(humanWeapon)
{
	
}

HumanA::~HumanA()
{
	std::cout << this->name << " destroyed" << std::endl;
}

void HumanA::attack() const 
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

