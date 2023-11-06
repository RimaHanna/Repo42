#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string name); // Constructor to initialize a zombie with a name
        ~Zombie(void);            // Destructor to clean up when a zombie is destroyed
        void announce(void);      // Member function to make a zombie announce itself
};

Zombie* newZombie(std::string name); // Function declaration to create a new zombie

void randomChump(std::string name); // Function declaration to create a random zombie

#endif

