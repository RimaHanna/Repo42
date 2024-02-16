#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

// The printElement function template takes an element of type T
// and prints it to the standard output.
// Parameter:
//   - element: The element to be printed.
template <typename T>
void printElement(T &element)
{
    std::cout << element << std::endl;
}

// The iter function template takes an array, its length, and a function,
// and applies the provided function to each element of the array.
// Parameters:
//   - array: The address of an array.
//   - length: The length of the array.
//   - func: A function to be applied to each element of the array.
template <typename T>
void iter(T *array, size_t length, void (*func)(T &element))
{
    size_t i = 0;
    while (i < length)
    {
        func(array[i]);
        i++;
    }
}

#endif