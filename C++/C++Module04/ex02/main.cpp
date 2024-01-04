#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>


int main()
{
    /*Since it is an abstract class, we cannot instantiate a class from AANimal,
    it has to be done from a inherited/derived class*/
//    std::cout << "\033[34mCreating meta animal---\033[0m" << std::endl;
//    const AAnimal* meta = new AAnimal();
    std::cout << std::endl;
    std::cout << "\033[34mCreating j animal------\033[0m" << std::endl;
    const AAnimal* j = new Dog();
    std::cout << std::endl;
    std::cout << "\033[34mCreating i animal\033[0m" << std::endl;
    const AAnimal* i = new Cat();
    std::cout << std::endl;
    std::cout << "\033[34mGetting the types------\033[0m" << std::endl;
    std::cout << "\033[34mType of j: \033[0m" <<j->getType() << std::endl;
    std::cout << "\033[34mType of i: \033[0m" <<i->getType() << std::endl;
    std::cout << std::endl;
    std::cout << "\033[34mSounds of animals------\033[0m" << std::endl;
    std::cout << "\033[34mCat sound \033[0m"; 
    i->makeSound(); //will output the cat sound!
    std::cout << "\033[34mDog sound \033[0m";
    j->makeSound(); //will output the dog sound!
    std::cout << std::endl;
    std::cout << "\033[34mFreeing the memory-----\033[0m" << std::endl;
    delete j;
    delete i;

    std::cout << std::endl;
    return 0;
}
