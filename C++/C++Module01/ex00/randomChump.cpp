#include "Zombie.hpp"

/**
 * randomChump.cpp:
 * Function to create a zombie on the stack with a provided name.
 * The zombie announces itself.
*/

// Function to create a random zombie and make it announce itself
void randomChump(std::string name)
{
    // Create a zombie on the stack with the provided name
    Zombie z = Zombie(name);

    // Make the zombie announce itself
    z.announce();
}
