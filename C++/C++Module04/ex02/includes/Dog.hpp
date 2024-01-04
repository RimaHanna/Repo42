#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal
{
    public:
        Dog();
        virtual ~Dog();

        Dog(const Dog &other);
        Dog &operator = (const Dog &other);

        virtual void makeSound(void) const;
        
    private:
        Brain* brain;
};


#endif // DOG_HPP