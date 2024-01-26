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
    int choice = rand() % 3;
    switch (choice)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return 0;
    }
}

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