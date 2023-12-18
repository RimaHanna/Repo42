#include "Zombie.hpp"

/**
 * newZombie.cpp:
 * Function to dynamically allocate a new zombie and return a pointer to it.
*/

/*
Zombie* newZombie(std::string name)
{
    // Dynamically allocate a new zombie and return a pointer to it
    return new Zombie(name);
}
*/

// Function to create a new zombie and return a pointer to it
Zombie* newZombie(std::string name)
{
    // Dynamically allocate a new zombie.
    Zombie *zombie = new Zombie(name);
    
    // Return a pointer to the created zombie
    return zombie;
}
