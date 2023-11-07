#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
	    std::string type;

	public:
	    // Constructor for Weapon, initializes the weapon type
	    Weapon(const std::string& weaponType);

    	// Getter for retrieving the weapon type
	    const std::string& getType() const;

	    // Setter for modifying the weapon type
		void setType(const std::string& newType);
};

#endif
