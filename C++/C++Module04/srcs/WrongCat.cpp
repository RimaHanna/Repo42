#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    this->setType("WrongCat");
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    *this = other;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat &original)
{
    *this = original;
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat Meows!" << std::endl;
}
