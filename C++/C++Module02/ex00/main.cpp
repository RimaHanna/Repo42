#include "Fixed.hpp"

int main( void )
{
    // Default constructor called
    Fixed a;

    // Copy constructor called
    Fixed b(a);

    // Default constructor called
    Fixed c;

    // Copy assignment called
    c = b;
    
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
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