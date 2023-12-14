#include "Fixed.hpp"

// Default constructor;
Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Constructor with Parameter const int;
/*
 It's initializing the value member with a fixed-point representation of the integer consInt.
 The expression consInt * (1 << Fixed::bits) is used to convert the integer to a fixed-point representation.
*/
Fixed::Fixed(const int consInt) : value(consInt * (1<<Fixed::bits))
{
    std::cout << "Int constructor called" << std::endl;
}

// Constructor with Parameter const floating-point
Fixed::Fixed(const float flowInt) : value(roundf(flowInt *(1<<Fixed::bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignement operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->setRawBits(other.getRawBits());
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->value / (float)(1 << Fixed::bits);
}

int Fixed::toInt(void) const
{
    return this->value >> Fixed::bits;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}