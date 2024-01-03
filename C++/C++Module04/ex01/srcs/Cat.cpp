#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal()
{
    this->setType("Cat");
    try
    {
        this->brain = new Brain();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    this->type = other.type;
    this->brain = new Brain();
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator = (const Cat &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Cat copy assignement operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows!" << std::endl;
}
