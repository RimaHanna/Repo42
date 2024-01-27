#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::endl;

Base* generate(void)
{
    srand((unsigned) time(NULL)); 
    char choice = "ABC"[rand() % 3];

    cout << "Type '" << choice << "' created" << endl;
    switch (choice)
    {
        case 'A':
            return new A();
        case 'B':
            return new B();
        case 'C':
            return new C();
    }
    return NULL;
}

/**
 * dynamic_cast is primarily used for downcasting, which means converting 
 * a pointer or reference of a base class to a pointer or reference of a 
 * derived class.
 * 
 * The classes involved in dynamic_cast must be polymorphic, i.e., 
 * they must have at least one virtual function. This is because dynamic_cast 
 * uses runtime type information (RTTI) to perform the cast.
 * 
 * Syntax:
 *      dynamic_cast<DerivedType*>(BasePointer)
 *      dynamic_cast<DerivedType&>(BaseReference)
 * 
 * Return Value:
 *  If the cast is successful, it returns a pointer or reference to the derived type.
 *  If the cast is not possible (e.g., the actual object is not of the derived type), 
 * it returns a null pointer for pointers or throws a std::bad_cast exception for references.
*/

void identify(Base* p)
{
    cout << "Attempting to identify type with *: " << endl;
    if (dynamic_cast<A *>(p))
        cout << "A" << endl;
    else if (dynamic_cast<B *>(p))
        cout << "B" << endl;
    else if (dynamic_cast<C *>(p))
        cout << "C" << endl;
    else
        cout << "Null type" << endl;
}

void identify(Base& p)
{
    cout << "Attempting to identify type with &:" << endl;
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void) a;
        cout << "A" << endl; 
    }
    catch(const std::exception& e)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            (void) b;
            cout << "B" << endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                (void) c;
                cout << "C" << endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << "Invalid type" << '\n';
            }   
        }   
    }
}

int main(int argc, char **argv)
{
    if (argc > 1 && argv)
    {
        std::cerr << "Error: The 'serializer' executable does not accept command-line arguments." << endl;
        return 1;
    }
    Base *p = generate();
    identify(p);
    identify (*p);
    delete p;
    return 0;
}