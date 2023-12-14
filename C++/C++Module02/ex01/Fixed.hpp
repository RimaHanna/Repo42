#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int bits = 8;
    public:
        // Default constructor;
        Fixed();

        // Constructor with Parameter const int;
        Fixed(const int consInt);

        // Constructor with Parameter const floating-point;
        Fixed(const float flowInt);

        // Copy Constructor
        Fixed(const Fixed & other);

        // Copy assignement operator overload
        Fixed &operator = (const Fixed &other);

        // Destructor
        ~Fixed();

        // Member function to get the Raw bits
        int getRawBits(void) const;

        // Member functions to set the Raw bits
        void setRawBits(int const raw);

        // Member function float to float
        float toFloat(void) const;

        // Member function int to int;
        int toInt(void) const;
};


    // Implimentation File
    /* 
    std::ostream &: This is the return type of the operator<< overload. 
    It specifies that the function should return a reference 
    to an std::ostream object. Returning a reference allows for 
    chaining multiple output operations together.

    operator<<(std::ostream &stream, const Fixed &nbr): 
    This is the declaration of the << operator overload function. 
    It takes two parameters:

    std::ostream &stream: A reference to an std::ostream object. 
    This represents the output stream where the data will be inserted.
    const Fixed &nbr: A reference to a const Fixed object. 
    This is the object whose representation you want to insert into 
    the output stream.
    */
    std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);
#endif