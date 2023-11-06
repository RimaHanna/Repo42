#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	int i;
	Zombie *horde; // equivalent to char *str;

	i = 0;
	horde = new Zombie[n]; // equivalenet to str = malloc(size of char)
	while (i < n)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}