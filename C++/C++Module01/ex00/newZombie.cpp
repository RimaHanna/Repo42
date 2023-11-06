#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    // Dynamically allocate a new zombie and return a pointer to it
    return (new Zombie(name));
}
