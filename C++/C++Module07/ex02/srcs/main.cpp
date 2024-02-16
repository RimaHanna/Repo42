#include "Array.hpp"

int main() {
    try {
        // Create an empty array
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.getSize() << std::endl;

        // Create an array with 5 elements
        Array<int> intArray(5);
        std::cout << "Array size: " << intArray.getSize() << std::endl;

        // Access elements and modify
        for (size_t i = 0; i < intArray.getSize(); ++i) {
            intArray[i] = i * 10;
        }

        // Display elements
        std::cout << "Array elements: ";
        for (size_t i = 0; i < intArray.getSize(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Access an element out of range (should throw an exception)
        intArray[intArray.getSize()] = 100; // Access one element beyond the array size

        // Copy constructor and assignment operator tests
        Array<int> copiedArray = intArray; // Copy constructor
        Array<int> assignedArray;
        assignedArray = intArray; // Assignment operator

        // Modify the original array and check if it affects the copied/assigned arrays
        intArray[0] = 999;
        std::cout << "Copied array after modifying original: ";
        for (size_t i = 0; i < copiedArray.getSize(); ++i) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Assigned array after modifying original: ";
        for (size_t i = 0; i < assignedArray.getSize(); ++i) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
