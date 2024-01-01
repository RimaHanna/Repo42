#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        virtual ~WrongCat();

        WrongCat(const WrongCat &other);
        WrongCat &operator = (const WrongCat &other);
        
        void makeSound(void) const;
};

#endif //WRONGCAT_HPP