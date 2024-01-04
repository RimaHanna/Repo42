#include "AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal()
{
    std::cout << "AAnimal default constructor called" << std::endl; 
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl; 
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "AAnimal copy constructor called" << std::endl; 
    *this = other;
}

AAnimal& AAnimal::operator = (const AAnimal &other)
{
    this->type = other.type;
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    return *this;
}

void AAnimal::setType(std::string type)
{
    this->type = type;
}

std::string AAnimal::getType(void) const
{
    return this->type;
}

void AAnimal::makeSound(void) const
{
    std::cout << "AAnimal makes a generic sound" << std::endl;
}