#include "Serializer.hpp"

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

/*
 * The aim of the exercise is to create a class named Serializer with two static 
 * methods: serialize and deserialize. These methods allow converting a pointer 
 * to a Data object into an unsigned integer (uintptr_t) and vice versa. 
 * The purpose is to demonstrate how to serialize and deserialize a pointer,
 * storing its memory address in an integer and then restoring the original 
 * pointer from that integer.
*/

int main(int argc, char **argv)
{
    if (argc > 1 && argv)
    {
        cerr << "Error: The 'serializer' executable does not accept command-line arguments." << endl;
        return 1;
    }

    Data *object = new Data();
    cout << "Data objectect created" << endl;

    object->aloha = "Bonnnnjourrr !!!";
    cout << object->aloha << endl;
    cout << "Address for object before serialized is " << object << endl; 

    uintptr_t serialized;
    serialized = Serializer::serialize(object);
    cout << "Address for serialized is " << serialized << endl; 

    object = Serializer::deserialize(serialized);
    cout << "Address for object after serialized and deserialized is " << object << endl; 

    return 0;
}