#include "Fixed.hpp"

int main( void )
{
    // Default constructor called
    std::cout << "Fixed a" << std::endl;
    Fixed a;
    std::cout << std::endl; 

    // Copy constructor called
    std::cout << "Fixed b(a)" << std::endl;
    Fixed b(a);
    std::cout << std::endl;

    // Default constructor called
    std::cout << "Fixed c" << std::endl;
    Fixed c;
    std::cout << std::endl;

    // Copy assignment called
    std::cout << "Fixed c = b" << std::endl;
    c = b;
    std::cout << std::endl;
    
    std::cout << "a.getRawBits" << std::endl;
    std::cout << a.getRawBits() << std::endl;
    std::cout << std::endl;
    std::cout << "b.getRawBits" << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << std::endl;
    std::cout << "c.getRawBits" << std::endl;
    std::cout << c.getRawBits() << std::endl;
    std::cout << std::endl;
    return 0;
}

/*
// OUTPUT SHOULD BE
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
*/