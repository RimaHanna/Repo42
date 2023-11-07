#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
	    std::string name;
	    Weapon& weapon;

	public:

	    // Constructor for HumanA, takes a name and a reference to a weapon
	    HumanA(const std::string& humanName, Weapon& humanWeapon);

		// Destructor
		~HumanA();

    	// Function to perform an attack with the weapon
	    void attack() const;
};

#endif
