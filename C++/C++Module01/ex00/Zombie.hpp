#pragma once

#include <iostream>
#include <string>


/**
 * Zombie.hpp:
 * Zombie class declaration with a private member _name and public member functions.
 * Zombie constructor initializes a zombie with a name.
 * ~Zombie destructor prints a message when a zombie is destroyed.
 * announce function makes a zombie announce itself.
 * Function declarations for newZombie and randomChump.
*/

class Zombie {
private:
    std::string _name;

public:
    // Constructor to initialize a zombie with a name
    Zombie(std::string name);

    // Destructor to clean up when a zombie is destroyed
    ~Zombie(void);

    // Member function to make a zombie announce itself
    void announce(void);
};

// Function declaration to create a new zombie
Zombie* newZombie(std::string name);

// Function declaration to create a random zombie
void randomChump(std::string name);
