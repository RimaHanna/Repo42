#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>


/*
    The aim of ex00 is to inherit a class from a base class,
    it inherits the public and the protected things in this class,
    when we use "virtual" it means we can override over this function
*/

int main()
{
    std::cout << "\033[34mCreating meta animal---\033[0m" << std::endl;
    const Animal* meta = new Animal();
    std::cout << std::endl;
    std::cout << "\033[34mCreating j animal------\033[0m" << std::endl;
    const Animal* j = new Dog();
    std::cout << std::endl;
    std::cout << "\033[34mCreating i animal\033[0m" << std::endl;
    const Animal* i = new Cat();
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
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "\033[34mFreeing the memory-----\033[0m" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << "\033[31m---------- WrongAnimal & WrongCat ----------\033[0m" << std::endl;

    std::cout << "\033[34mCreating wrong_cat----\033[0m" << std::endl;
	const WrongAnimal* wrong_cat = new WrongCat();
    std::cout << std::endl;
    std::cout << "\033[34mCreating meta_wrong_animal----\033[0m" << std::endl;
	const WrongAnimal* meta_wrong_animal = new WrongAnimal();
	std::cout << std::endl;
    std::cout << "\033[34mGetting the types------\033[0m" << std::endl;
    std::cout << "\033[34mType of wrong_cat: \033[0m" << wrong_cat->getType() << std::endl;
	std::cout << std::endl;
    std::cout << "\033[34mSounds of animals------\033[0m" << std::endl;
    std::cout << "\033[34mWrong_cat sound:\033[0m "; //will output the Wrong animal sound!
    wrong_cat->makeSound();
    std::cout << "\033[34mmeta_wrong_animal sound:\033[0m ";
    meta_wrong_animal->makeSound();
    std::cout << std::endl;
    std::cout << "\033[34mFreeing the memory-----\033[0m" << std::endl;
	delete wrong_cat;
	delete meta_wrong_animal;
    return 0;
}
