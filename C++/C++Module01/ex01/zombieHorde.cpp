#include "Zombie.hpp"

// Function to create a Zombie horde with the specified name
Zombie *zombieHorde(int n, std::string name)
{
    int i;
    Zombie *horde; // Equivalent to char *str;

    i = 0;
    horde = new Zombie[n]; // Equivalent to str = malloc(size of char)
    while (i < n)
    {
        horde[i].setName(name);
        i++;
    }
    return (horde);
}