#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

//#define LOGS

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
      
            // Comparison operators
        bool operator<(const Fixed& nbr);
        bool operator>(const Fixed& nbr);
        bool operator<=(const Fixed& nbr);
        bool operator>=(const Fixed& nbr);
        bool operator==(const Fixed& nbr);
        bool operator!=(const Fixed& nbr);

            // Arithmic operators
        Fixed operator+(const Fixed& nbr);
        Fixed operator/(const Fixed& nbr);
        Fixed operator*(const Fixed& nbr);
        Fixed operator-(const Fixed& nbr);

        // Pre-Increment / pre-Decrement operators
                // Pre-increment:  it returns a reference to a Fixed object (Fixed &). 
                //  The return type is a reference because it allows you to chain multiple 
                //  increment operations together, like ++a = b;
        Fixed &operator++(void);
                // Pre-decrement
        Fixed &operator--(void);

        // Post-Incerment / Post-decrement operators
                // Post-increment
                // The int parameter is a dummy parameter, and it is used to differentiate 
                //  between the pre-increment and post-increment operators. 
                //  The return type is Fixed, and it ***returns the original value before the increment***.
        Fixed operator++(int);
                // Post-decrement
        Fixed operator--(int);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);
};
    std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);
#endif