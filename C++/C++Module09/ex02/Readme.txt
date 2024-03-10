CONTAINERS
------------------------------------------------------------
### std::vector

- **Description**: 
  - `std::vector` is a sequence container that stores elements in a dynamically allocated array.
        It is part of the C++ Standard Template Library (STL) and provides dynamic array functionality with automatic resizing.
  - Elements are stored in contiguous memory locations, allowing for efficient access and traversal using iterators.

- **Features**:
  - **Dynamic Size**: Unlike arrays, vectors can change in size dynamically during runtime.
    They automatically handle memory allocation and deallocation as elements are added or removed.
  - **Random Access**: Elements in a vector can be accessed in constant time using index-based access (i.e., `vec[index]`).
  - **Resizable**: Vectors can grow or shrink dynamically, allowing for flexible storage of elements.
  - **Efficient Insertion and Deletion**: While insertion and deletion operations at the end of 
    the vector (`push_back`, `pop_back`) are efficient, operations in the middle or beginning 
    of the vector may require elements to be shifted, which can be less efficient.

- **Use Cases**:
  - Vectors are suitable for scenarios where efficient random access and dynamic resizing are required.
  - They are commonly used in algorithms that involve frequent access to elements, such as sorting and searching algorithms.

### std::deque

- **Description**: 
  - `std::deque` (double-ended queue) is a sequence container that supports dynamic resizing and provides 
  efficient insertion and deletion operations at both ends (front and back).
  - Internally, `std::deque` is implemented as a sequence of fixed-size arrays (blocks) linked together, 
  allowing for efficient insertion and deletion operations at both ends.

- **Features**:
  - **Dynamic Size**: Similar to vectors, deques can change in size dynamically during runtime.
  - **Efficient Insertion and Deletion at Both Ends**: Deques support efficient insertion and 
  deletion operations at both the front (`push_front`, `pop_front`) and 
  back (`push_back`, `pop_back`) ends, with constant time complexity.
  - **Random Access**: Elements in a deque can be accessed in constant time using 
  index-based access (i.e., `deq[index]`), but it may be slightly less efficient than 
  vectors due to the block-based internal storage.

- **Use Cases**:
  - Deques are suitable for scenarios where efficient insertion and deletion operations are 
  required at both ends of the container.
  - They are commonly used in scenarios where elements need to be added or removed frequently 
  from both ends, such as queues and double-ended queues.

                                    -----------------------------------------------------

FORD-JOHNSON ALGORITHM
------------------------------

The Ford-Johnson algorithm, also known as the merge-insertion sort algorithm, is a sorting algorithm 
that combines the merge sort and insertion sort techniques. Here's a brief explanation of how it works:

1. **Divide and Conquer**: Like merge sort, the Ford-Johnson algorithm follows a divide-and-conquer 
approach. It divides the input array into smaller subarrays until each subarray contains a single 
element, which is already considered sorted.

2. **Merge Sort**: It then merges adjacent subarrays in a pairwise manner, combining them into larger 
sorted subarrays. This merging process continues until the entire array is sorted. This part of the 
algorithm is similar to merge sort and is often implemented recursively.

3. **Insertion Sort**: However, instead of recursively dividing the array until it reaches 
single-element subarrays, the Ford-Johnson algorithm switches to insertion sort for small 
subarrays. When the size of a subarray becomes small enough (often a threshold value), 
the algorithm switches to insertion sort for efficiency.

4. **Combining Merge and Insertion Sort**: By combining merge sort's efficient divide-and-conquer 
strategy with insertion sort's efficiency for small arrays, the Ford-Johnson algorithm achieves a 
balance between the two approaches. It can handle large input arrays efficiently while also being 
suitable for small arrays due to the efficient insertion sort component.

Overall, the Ford-Johnson algorithm offers a practical compromise between the runtime 
efficiency of merge sort and the simplicity and efficiency of insertion sort, making 
it a versatile sorting algorithm for various input sizes and types.