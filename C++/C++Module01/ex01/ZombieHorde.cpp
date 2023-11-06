#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	int i = 0;
	Zombie *horde = new Zombie[n];
	while (i < n)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}