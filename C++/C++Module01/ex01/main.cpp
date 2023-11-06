#include "Zombie.hpp"

int main(void)
{
	int i = 0;
	int n = 4;

	Zombie *horde = zombieHorde(n, "Rima");
	while(i < n)
	{
		horde[i].announce();
		i++;
	}
	delete[]horde;
	return (0);
} 
