#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "";
}

Zombie::~Zombie()
{
	std::cout << "Zombie object " <<this->_name << " destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << " Braiiiinnnzzzz....." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	std::cout << "Zombie object " << this->_name << " created" << std::endl;;
}