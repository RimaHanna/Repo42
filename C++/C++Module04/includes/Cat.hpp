#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
    public:
        Cat();
        virtual ~Cat();

        Cat(const Cat &other);
        Cat &operator = (const Cat &original);
        
        virtual void makeSound(void) const;

};

#endif // CAT_HPP