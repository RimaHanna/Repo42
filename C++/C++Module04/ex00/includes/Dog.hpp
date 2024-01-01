#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
    public:
        Dog();
        virtual ~Dog();

        Dog(const Dog &other);
        Dog &operator = (const Dog &other);

        virtual void makeSound(void) const;
        
};


#endif // DOG_HPP