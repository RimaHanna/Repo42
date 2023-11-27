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

// Main function
int main(void)
{
    int i;
    int n;
    Zombie *horde;

    i = 0;
    n = 4;
    horde = zombieHorde(n, "Rima");
    while (i < n)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde; // Free memory allocated for the Zombie horde
    return (0);
}
