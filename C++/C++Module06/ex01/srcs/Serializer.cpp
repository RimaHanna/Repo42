#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
    *this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void) other;
    return *this;
}

// Use reinterpret_cast for low-level type conversions between pointers and integral types.
// Exercise caution, as it bypasses type safety and can lead to undefined behavior if misused.
// Prefer safer alternatives like static_cast, dynamic_cast, or const_cast when applicable.

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}