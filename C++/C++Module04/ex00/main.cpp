#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>


int main()
{
    std::cout << "Creating meta animal---" << std::endl;
    const Animal* meta = new Animal();
    std::cout << std::endl;
    std::cout << "Creating j animal------" << std::endl;
    const Animal* j = new Dog();
    std::cout << std::endl;
    std::cout << "Creating i animal" << std::endl;
    const Animal* i = new Cat();
    std::cout << std::endl;
    std::cout << "Getting the types------" << std::endl;
    std::cout << "Type of j: " <<j->getType() << std::endl;
    std::cout << "Type of i: " <<i->getType() << std::endl;
    std::cout << std::endl;
    std::cout << "Sounds of animals------" << std::endl;
    std::cout << "Cat sound"; 
    i->makeSound(); //will output the cat sound!
    std::cout << "Dog sound";
    j->makeSound(); //will output the dog sound!
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "Freeing the memory-----" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << "---------- WrongAnimal & WrongCat ----------" << std::endl;

    std::cout << "Creating wrong_cat----" << std::endl;
	const WrongAnimal* wrong_cat = new WrongCat();
    std::cout << std::endl;
    std::cout << "Creating meta_wrong_animal----" << std::endl;
	const WrongAnimal* meta_wrong_animal = new WrongAnimal();
	std::cout << std::endl;
    std::cout << "Getting the types------" << std::endl;
    std::cout << "Type of wrong_cat: " <<wrong_cat->getType() << std::endl;
    std::cout << "Type of meta_wrong_animal: " <<meta_wrong_animal->getType() << std::endl; 
	std::cout << std::endl;
    std::cout << "Sounds of animals------" << std::endl;
    std::cout << "Wrong_cat sound: "; //will output the Wrong animal sound!
    wrong_cat->makeSound();
    std::cout << "meta_wrong_animal sound: ";
    meta_wrong_animal->makeSound();
    std::cout << std::endl;
    std::cout << "Freeing the memory-----" << std::endl;
	delete wrong_cat;
	delete meta_wrong_animal;
    return 0;
}

/*
int	main(void)
{
	std::cout << "---------- WrongAnimal & WrongCat ----------" << std::endl;

	const WrongAnimal* wrong_cat = new WrongCat();
	const WrongAnimal* meta_wrong_animal = new WrongAnimal();

	std::cout << std::endl;

	std::cout << wrong_cat->getType() << "-> "; 
	wrong_cat->makeSound();

	meta_wrong_animal->makeSound();

	std::cout << std::endl;

	delete wrong_cat;
	delete meta_wrong_animal;

	return 0;
}
*/