#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

/**
 Objects of an abstract class cannot be created directly.
 You can only create instances of classes 
 that derive from the abstract class.
*/

class AAnimal
{
    public:
        AAnimal();
        virtual ~AAnimal();

        AAnimal(const AAnimal &other);
        AAnimal& operator=(const AAnimal &other);

        void setType(std::string type);
        std::string getType(void) const;

        // To be an abstract class, it should contain 
        // at least one pure virtual function
        virtual void makeSound(void) const = 0;

    protected:
        std::string type;
};


#endif // AANIMAL_HPP