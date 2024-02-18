#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array {
private:
    T* elements; // Pointer to array elements
    size_t size; // Number of elements in the array

public:
    // Default constructor (creates an empty array)
    Array();

    // Constructor with a parameter (creates an array of n elements initialized by default)
    // The 'explicit' keyword prevents implicit conversions from size_t to Array
    explicit Array(size_t n);

    // Destructor
    ~Array();

    // Copy constructor
    Array(const Array& other);

    // Assignment operator
    Array& operator=(const Array& other);

    // Subscript operator
    T& operator[](size_t index);

    // Member function to get the size of the array
    size_t getSize() const;
};

#include "Array.tpp"

#endif // ARRAY_HPP