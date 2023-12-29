#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal()
{
    this->setType("Cat");
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator = (const Cat &original)
{
    *this = original;
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows!" << std::endl;
}
