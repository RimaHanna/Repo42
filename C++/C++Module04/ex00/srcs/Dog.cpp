#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal()
{
    this->setType("Dog");
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator = (const Dog &other)
{
    *this = other;
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks!" << std::endl;
}
