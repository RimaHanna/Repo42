#include "iter.hpp"
#include <iostream>

/**
 * size_t intArrayLength = sizeof(intArray) / sizeof(int);
 * This method calculates the total size of the array in bytes 
 * (sizeof(myArray)) and divides it by the size of one element 
 * (sizeof(myArray[0])) to get the number of elements.
*/

int main()
{
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    std::cout << "Iterating over intArray: " << std::endl;
    ::iter(intArray, intArrayLength, &::printElement<int>);
    std::cout << std::endl;

    // Test with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

    std::cout << "Iterating over doubleArray: " << std::endl;
    ::iter(doubleArray, doubleArrayLength, ::printElement<double>);
    std::cout << std::endl;

    // Test with an array of strings
    std::string stringArray[] = {"apple", "banana", "orange"};
    size_t stringArrayLength = sizeof(stringArray) / sizeof(std::string);

    std::cout << "Iterating over stringArray: " << std::endl;
    ::iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
