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
        
        // didn't add virtual infront of this 
        // function, which means the WrognCat will
        // inherit the message of WrongAnimal
        void makeSound(void) const;
};

#endif //WRONGCAT_HPP