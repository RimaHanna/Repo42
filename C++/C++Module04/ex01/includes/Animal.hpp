#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

/**
 * Public: Accessible from any part of the program
 * Protected: Accessible from the class and its derived classes
 * Private: Accessible from the class
*/

class Animal
{
    public:
        Animal();
        virtual ~Animal();

        Animal(const Animal &other);
        Animal& operator=(const Animal &other);

        void setType(std::string type);
        std::string getType(void) const;

        virtual void makeSound(void) const;

    protected:
        std::string type;
};


#endif // ANIMAL_HPP