#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <string>
#include <stdint.h>

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        ~Serializer();

    public:
        // Serialize a pointer to a Data object into an unsigned integer
        // Parameters:
        //   - ptr: A pointer to a Data object
        // Returns:
        //   An unsigned integer (uintptr_t) representing the memory address of the Data object
        // Note:
        //   The serialization allows storing the memory address of the Data object as an integer.
        //   The deserialization process can later convert this integer back to a pointer.
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif