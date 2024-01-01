#include "Animal.hpp"

#include <iostream>

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl; 
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl; 
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl; 
    *this = other;
}

Animal& Animal::operator = (const Animal &other)
{
    this->type = other.type;
    std::cout << "Animal copy assignment operator called" << std::endl;
    return *this;
}

void Animal::setType(std::string type)
{
    this->type = type;
}

std::string Animal::getType(void) const
{
    return this->type;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal makes a generic sound" << std::endl;
}