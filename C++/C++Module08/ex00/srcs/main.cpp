#include <iostream>
#include <vector>
#include "easyfind.hpp"
#include <set>
#include <list>

int main(void)
{
	// USING VECTOR CONTAINER std::vector<int> named vec1 //
	std::cout << "USING VECTOR CONTAINER" << std::endl;
	std::vector<int> vec1; 
	for (size_t i = 0; i <= 10; i += 1)
		vec1.push_back(i); // add elements to the end of the vector

	std::cout << "Display vec1: " << std::endl;
	for (std::vector<int>::iterator iter = vec1.begin(), endIter = vec1.end(); iter != endIter; iter += 1)
		std::cout << *iter << " ";
	std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "TEST 1 find the number 5" << std::endl;
    try
    {
        bool found = easyfind(vec1, 5);
        if (found)
            std::cout << "Element found in vec1" << std::endl;
    }
    catch (const std::exception& e)
    {
	    std::cerr << e.what() << '\n';
    }
	std::cout << std::endl;
    
    std::cout << "TEST 2 find the number 20" << std::endl;
	try
    {
		easyfind(vec1, 20);
	}
	catch (const std::exception& e)
    {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

// USING LIST CONTAINER
	std::cout << "USING LIST CONTAINER" << std::endl;
    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    myList.push_back(50);

    try
	{
		int toFind = 30;
        bool found = easyfind(myList, toFind);
        if (found)
            std::cout << "Element " << toFind << " found in list." << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

/*
Containers in C++ are data structures that store and organize elements in memory.
They provide various functionalities for accessing, inserting, and removing elements,
as well as iterating over them. C++ provides several container classes in its Standard
Template Library (STL), each serving different purposes and offering different performance
characteristics. Here's an overview of some commonly used containers in C++:

Sequence Containers:

Array: A fixed-size sequential container that stores elements of the same type in contiguous memory locations.
Vector: A dynamic array that automatically adjusts its size as elements are added or removed. 
        It provides random access to elements.
Deque: A double-ended queue that supports efficient insertion and deletion of elements at both ends.
List: A doubly linked list that allows for efficient insertion and removal of elements at any position.

Each container provides different operations for manipulating elements, 
such as insertion, deletion, and searching. Choosing the right container 
depends on factors like the required operations, performance characteristics, 
and memory overhead. 
The STL containers are designed to be efficient and easy to use, providing a 
wide range of options to suit various programming needs.

Explanation depending on my requirements and the characteristics of the container
Vectors (std::vector): Suitable for scenarios where you need dynamic resizing 
and random access to elements. They are efficient for searching 
if the elements are not sorted.

Lists (std::list): Suitable for scenarios where you frequently 
insert or delete elements from the middle of the container. 
However, searching in a list is less efficient compared 
to vectors due to linear traversal.

Sets (std::set) and Maps (std::map): Suitable for scenarios
 where you need unique elements or key-value pairs. 
 Sets are ordered containers, while maps are associative 
 containers that store key-value pairs. Searching in sets 
 and maps is efficient due to their internal data 
 structures (e.g., binary search tree for sets).

Deque (std::deque): Suitable for scenarios where you 
need efficient insertion and deletion at both ends 
of the container. It also supports random access like vectors.
*/