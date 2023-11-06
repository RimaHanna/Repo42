#include "Zombie.hpp"

void randomChump(std::string name)
{
    // Create a zombie on the stack with the provided name
    Zombie z = Zombie(name);

    // Make the zombie announce itself
    z.announce();
}