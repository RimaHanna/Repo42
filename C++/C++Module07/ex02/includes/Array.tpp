// elements(NULL): Initializes the elements pointer to NULL, indicating that no memory is allocated for elements.
// size(0): Initializes the size member variable to 0, indicating that the array has zero elements.
template<typename T>
Array<T>::Array() : elements(NULL), size(0)
{
    // std::cout << "Default constructor called!" << std::endl;
}

template<typename T>
Array<T>::Array(size_t n) : size(n)
{
    elements = new T[n](); // Default initialization of elements
}

template<typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template<typename T>
Array<T>::Array(const Array& other) : size(other.size)
{
    elements = new T[size];
    for (size_t i = 0; i < size; ++i)
    {
        elements[i] = other.elements[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other) // Avoid self-assignment
    {
        // Deallocate existing memory so if i have an original array of 10 elements
        // and in the other i have 5, i delete
        delete[] elements;
        // Allocate new memory and copy elements
        size = other.size;
        elements = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

template<typename T>
size_t Array<T>::getSize() const
{
    return size;
}
