#include "Zombie.hpp"

// Constructor: Initializes the attribute, but it is not necessary
Zombie::Zombie()
{
    this->_name = "";
}

// Destructor: Displays a message when a Zombie object is destroyed
Zombie::~Zombie()
{
    std::cout << "Zombie object " << this->_name << " destroyed" << std::endl;
}

// Member function: Announces the Zombie by printing its name
void Zombie::announce(void)
{
    std::cout << this->_name << " Braiiiinnnzzzz....." << std::endl;
}

// Member function: Sets the name of the Zombie and displays a creation message
void Zombie::setName(std::string name)
{
    this->_name = name;
    std::cout << "Zombie object " << this->_name << " created" << std::endl;;
}
