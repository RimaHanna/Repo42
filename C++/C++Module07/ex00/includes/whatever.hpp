#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/**
 * templates provide a way to create functions and classes that 
 * work with any data type. They allow you to write generic code
 * that can be used with different types without specifying the 
 * type beforehand.
 * The template <typename T> part is a declaration of a template parameter T.
 * It tells the compiler that the following code is a template, 
 * and T is a placeholder for a type that will be specified when the template is used.
*/

template <typename T>
void swap(T &a, T &b)
{
    std::swap(a, b);
}

template <typename T>
const T &min(T &a, T &b)
{
    return (a < b) ? a : b;
}

template <typename T>
const T &max(T &a, T &b)
{
    return (a > b) ? a : b;
}

#endif


