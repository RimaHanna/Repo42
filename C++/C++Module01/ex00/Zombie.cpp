#include "Zombie.hpp"

/**
 * Zombie.cpp:
 * Constructor and destructor implementations with debug messages.
 * Implementation of the announce function.
*/

// Constructor implementation
Zombie::Zombie(std::string name) 
{
    this->_name = name;
    std::cout << "Zombie object " << this->_name << " created" << std::endl;
}

// Destructor implementation
Zombie::~Zombie() 
{
    std::cout << "Zombie object " << this->_name << " destroyed" << std::endl;
}

// Member function to make a zombie announce itself
void Zombie::announce() 
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
