#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
	    std::string name;
	    Weapon* weapon;

	public:

	    // Constructor for HumanB, takes a name (without a weapon)
	    HumanB(const std::string& humanName);

		// Destructor
		~HumanB();

    	// Function to set the weapon for HumanB
	    void setWeapon(Weapon& humanWeapon);

    	// Function to perform an attack with or without a weapon
	    void attack() const;
};

#endif
