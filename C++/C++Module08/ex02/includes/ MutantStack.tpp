// Constructor: calls the base class constructor
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

// Copy constructor: initializes the MutantStack with another MutantStack
template <typename T>
MutantStack<T>::MutantStack (MutantStack const &other) : std::stack<T>(other) {}

// Assignment operator: assigns another MutantStack to this MutantStack
template <typename T>
MutantStack<T> &MutantStack<T>::operator = (MutantStack const &other) 
{
    std::stack<T>::operator=(other); // Call base class assignment operator
    return *this; // Return reference to this MutantStack
}

/*
    this->c: c is a member of std::stack that represents the underlying container. 
    It's not directly accessible from std::stack, but it's accessible through the 
    base class. this->c accesses the underlying container.
*/
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    // Accesses the underlying container (c) and gets its begin iterator
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

