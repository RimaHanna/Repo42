#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) {
    *this = other;
}

Serializer &Serializer::operator=(const Serializer &other) {
    (void) other;
    return *this;
}

Serializer::~Serializer() {}

// Use reinterpret_cast for low-level type conversions between pointers and integral types.
// Integral types in C++ refer to data types that represent whole numbers 
// without any fractional or decimal part: int, unsigned int, short, unsigned short, long, unsigned long, 
// long long, unsigned long long, char, unsigned char
// Exercise caution, as it bypasses type safety and can lead to undefined behavior if misused.
// Prefer safer alternatives like static_cast, dynamic_cast, or const_cast when applicable.

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}