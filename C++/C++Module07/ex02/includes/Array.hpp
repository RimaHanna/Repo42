#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

template <typename T>
class Array {
private:
    T* elements; // Pointer to the array elements
    size_t arraySize; // Number of elements in the array

public:
    // Default constructor: creates an empty array
    Array();

    // Parameterized constructor: creates an array of n elements initialized by default
    explicit Array(size_t n);

    // Copy constructor
    Array(const Array& other);

    // Assignment operator
    Array& operator=(const Array& other);

    // Destructor
    ~Array();

    // Subscript operator for element access
    // Subscript operator [] overloads array access, providing bounds-checked element retrieval.
    // It allows accessing individual elements in the array using array-like indexing.
    // The operator returns a reference to the element at the specified index.
    // If the index is out of bounds, an std::out_of_range exception is thrown.
    T& operator[](size_t index);

    // Const version of the subscript operator for const-correctness
    // Having both versions of the subscript operator allows you to maintain 
    // const-correctness in your class, providing flexibility for users who 
    // need to work with both mutable and immutable instances of your Array class.
    const T& operator[](size_t index) const;

    // Member function to get the number of elements in the array
    size_t size() const;
};

/*-----------------------------------------------------------------------*/

template <typename T>
Array<T>::Array() : elements(NULL), arraySize(0)
{
    cout << "Default constructor called" << endl;
}

template <typename T>
Array<T>::Array(size_t n) : elements (new T[n]), arraySize(n)
{
    cout << "Parametrized constructor called" << endl;
}

// elements (new T[other.arraySize]) -> initializes the elements member with 
// a new dynamically allocated array of the same size as the other array.
// arraySize(other.arraySize) -> while it might not be strictly required, 
// initializing arraySize in the member initializer list is considered 
// good practice for clarity, maintainability, and to avoid potential issues.
template <typename T>
Array<T>::Array(const Array &other) : elements (new T[other.arraySize]), arraySize(other.arraySize)
{
    size_t i = 0;
    while (i < arraySize)
    {
        elements[i] = other.elements[i];
        i++; 
    }
    cout << "Copy constructor called" << endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other)
    {
        delete[] elements; // Free existing memory

        arraySize = other.arraySize;
        elements = new T[arraySize];

        for (size_t i = 0; i < arraySize; ++i)
        {
            elements[i] = other.elements[i];
        }
    }
    cout << "Copy assignement operator called" <<  endl;
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    cout << "Destructor called" << endl;
    delete[] elements;
}

// T& operator[](size_t index);
template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= arraySize)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
}

// const T& operator[](size_t index) const;
template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= arraySize)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return arraySize;
}

#endif
