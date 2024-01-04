#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" << std::endl; 
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl; 
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl; 
    *this = other;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal &other)
{
    this->type = other.type;
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return *this;
}

void WrongAnimal::setType(std::string type)
{
    this->type = type;
}

std::string WrongAnimal::getType(void) const
{
    return this->type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "\033[33mWrongAnimal makes a generic sound\033[0m" << std::endl;
}