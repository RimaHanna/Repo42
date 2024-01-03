#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>

int main()
{
    std::cout << "\033[36mCreate a Dog\033[0m" << std::endl;
    const Animal *roxy = new Dog();
    std::cout << std::endl;

    std::cout << "\033[36mCreate a Cat\033[0m" << std::endl;
    const Animal *sisi = new Cat(); 
    std::cout << std::endl;

    std::cout << "\033[36mCreate an animal objects\033[0m" << std::endl;
    const Animal* animals[4];
    std::cout << "\033[36mInitializing with half dog\033[0m" << std::endl;
    int i = 0;
    while (i < 2)
    {
        animals[i] = new Dog();
        i++;
    }
    std::cout << std::endl;

    std::cout << "\033[36mInitializing with half cat\033[0m" << std::endl;
    while (i < 4)
    {
        animals[i] = new Cat();
        i++;
    }
    std::cout << std::endl;

    std::cout << "\033[36mDeleting animals\033[0m" << std::endl;
    i = 0;
    while (i < 4)
    {
        delete animals[i];
        i++;
    }
    std::cout << std::endl;

    std::cout << "\033[36mDestroy and Free Dog\033[0m" << std::endl;
    delete roxy;
    std::cout << std::endl;

    std::cout << "\033[36mDestroy and Free Cat\033[0m" << std::endl;
    delete sisi;
    std::cout << std::endl;

    return 0;
}
