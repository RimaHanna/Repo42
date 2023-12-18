#include "Zombie.hpp"


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
