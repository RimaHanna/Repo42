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
        /* A copy constructor is a special member function 
         that initializes an object using another object 
         of the same class. It is used to create a copy 
         of an existing object.
        */
        Fixed(const Fixed & other);

        // Copy assignment operator overload
        /* The copy assignment operator overloading allows you to define 
         how an object of a class is assigned the value of another 
         object of the same class. 
        */
        Fixed &operator = (const Fixed &other);

        // Default destructor
        ~Fixed();

        // Member function to get the Raw bits
        int getRawBits(void) const;

        // Member functions to set the Raw bits
        void setRawBits(int const raw);
};

#endif //FIXED_HPP