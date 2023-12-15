#include "Fixed.hpp"

// Default constructor;
Fixed::Fixed() : value(0)
{
    #ifdef LOGS
        std::cout << "Default constructor called" << std::endl;
    #endif
}

// Constructor with Parameter const int;
Fixed::Fixed(const int consInt) : value(consInt * (1<<Fixed::bits))
{
    #ifdef LOGS
        std::cout << "Int constructor called" << std::endl;
    #endif
}

// Constructor with Parameter const floating-point
Fixed::Fixed(const float flowInt) : value(roundf(flowInt *(1<<Fixed::bits)))
{
    #ifdef LOGS
        std::cout << "Float constructor called" << std::endl;
    #endif
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    #ifdef LOGS
        std::cout << "Copy constructor called" << std::endl;
    #endif
    *this = other;
}

// Copy assignement operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
    #ifdef LOGS
        std::cout << "Copy assignement operator called" << std::endl;
    #endif
    this->setRawBits(other.getRawBits());
    return (*this);
}

Fixed::~Fixed()
{
    #ifdef LOGS
        std::cout << "Destructor called" << std::endl;
    #endif
}

int Fixed::getRawBits(void) const
{
    #ifdef LOGS
        std::cout << "getRawBits member function called" << std::endl;
    #endif
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

bool Fixed::operator>(const Fixed&  nbr)
{
    return (this->value > nbr.getRawBits());
}

bool Fixed::operator<(const Fixed& nbr)
{
    return (this->value < nbr.getRawBits());
}

bool Fixed::operator>=(const Fixed& nbr)
{
    return (this->value >= nbr.getRawBits());
}

bool Fixed::operator<=(const Fixed& nbr)
{
    return (this->value <= nbr.getRawBits());
}

bool Fixed::operator==(const Fixed& nbr)
{
    return (this->value == nbr.getRawBits());
}

bool Fixed::operator!=(const Fixed& nbr)
{
    return (this->value != nbr.getRawBits());
}


/* toFloat function is used to ensure that the arithmetic operations 
 are carried out using the correct precision and to handle the 
 fractional part of the fixed-point values.
*/
Fixed Fixed::operator+(const Fixed &nbr)
{
    return Fixed(this->toFloat() + nbr.toFloat());
}

Fixed Fixed::operator-(const Fixed &nbr)
{
    return Fixed(this->toFloat() - nbr.toFloat());
}

Fixed Fixed::operator/(const Fixed &nbr)
{
    return Fixed(this->toFloat() / nbr.toFloat());
}

Fixed Fixed::operator*(const Fixed &nbr)
{
    return Fixed(this->toFloat() * nbr.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->value += 1;
    return *this;
}

Fixed &Fixed::operator--(void)
{
    this->value -= 1;
    return *this;
}

// Make a copy before increment to return the original value
Fixed Fixed::operator++(int)
{
    Fixed temp(this->value *toFloat());
    this->value += 1;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(this->value *toFloat());
    this->value -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}