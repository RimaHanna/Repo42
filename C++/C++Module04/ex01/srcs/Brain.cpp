#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
    std::cout << "Brain constructor is called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
    int i = 0;
    while (i < 100)
    {   this->ideas[i] = other.ideas[i];
        i++;
    }
    std::cout << "Brain copy assignement operator called" << std::endl;
    return *this;

}