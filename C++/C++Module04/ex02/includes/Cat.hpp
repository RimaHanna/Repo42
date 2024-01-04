#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public AAnimal
{
    public:
        Cat();
        virtual ~Cat();

        Cat(const Cat &other);
        Cat &operator = (const Cat &other);
        
        virtual void makeSound(void) const;

    private:
        Brain* brain;
};

#endif // CAT_HPP