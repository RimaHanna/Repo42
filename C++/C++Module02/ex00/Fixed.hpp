#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int value;
        static const int bits = 8; 
    
    public:
        // Default constructor
        Fixed();

        // Copy constructor
        Fixed(const Fixed &copy_constructor);

        // Copy assignment operator overload
        Fixed &operator = (const Fixed &other);

        // Default destructor
        ~Fixed();

        // Member function to get the Raw bits
        int getRawBits(void) const;

        // Member functions to set the Raw bits
        void setRawBits(int const raw);
};

#endif //FIXED_HPP