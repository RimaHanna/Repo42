#include "Zombie.hpp"

int main(void)
{
    // Create a new zombie named "Rima" on the heap using newZombie function
    Zombie *zmb = newZombie("Rima");

    // Make the zombie "Rima" announce itself
    zmb->announce();

    // Create a random zombie named "Jessy" on the stack
    // and make it announce itself using randomChump function
    randomChump("Jessy");

    // Delete the dynamically allocated zombie to free memory
    delete zmb;

    return (0);
}
