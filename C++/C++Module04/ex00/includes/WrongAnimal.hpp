#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal& operator = (const WrongAnimal &other);

        void setType(std::string type);
        std::string getType(void) const;

        void makeSound(void) const;

    protected:
        std::string type;
};

#endif // WRONGANIMAL_HPP