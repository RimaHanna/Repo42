#include "Array.hpp"
#include <iostream>

int main() {
    // Test default constructor
    Array<int> intArrayDefault;
    std::cout << "Default Size: " << intArrayDefault.size() << std::endl;
    std::cout << std::endl;

    // Test constructor with size
    Array<double> doubleArray(5);
    doubleArray[0] = 1;
    doubleArray[1] = 1;
    doubleArray[2] = 1;
    doubleArray[3] = 1;
    doubleArray[4] = 1;
    std::cout << "Double Array Size: " << doubleArray.size() << std::endl;
    std::cout << std::endl;

    // Test copy constructor
    Array<double> doubleArrayCopy(doubleArray);
    std::cout << "Double Array Copy Size: " << doubleArrayCopy.size() << std::endl;
    std::cout << std::endl;

    // Test copy assignment operator
    Array<double> doubleArrayAssign;
    doubleArrayAssign = doubleArray;
    std::cout << "Double Array Assign Size: " << doubleArrayAssign.size() << std::endl;
    std::cout << "Value at index 2 (assigned): " << doubleArrayAssign[2] << std::endl;
    std::cout << std::endl;

    // Test subscript operator
    std::cout << "Subscript operator" << std::endl;
    doubleArray[2] = 3.14;
    std::cout << "Value at index 2: " << doubleArray[2] << std::endl;
    std::cout << std::endl;
    
    // Test const subscript operator
    std::cout << "const subscript operator" << std::endl;
    const Array<double> constDoubleArray(doubleArray);
    std::cout << "Value at index 2 (const): " << constDoubleArray[2] << std::endl;
    // Test accessing out-of-bounds index (should throw an exception)
    try
    {
        cout << "Try value at doubleArray[10]: " << endl;
        std::cout << doubleArray[10] << std::endl;
    } 
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
