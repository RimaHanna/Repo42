#include "Dog.hpp"

#include <iostream>

Dog::Dog() : AAnimal()
{
    this->setType("Dog");
    try
    {
        this->brain = new Brain();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
    this->type = other.type;
    this->brain = new Brain();
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator = (const Dog &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Dog copy assignement operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks!" << std::endl;
}
