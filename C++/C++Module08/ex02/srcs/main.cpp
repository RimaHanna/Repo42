#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "\033[38;5;206mUsing MutantStack\033[0m" << std::endl;
    MutantStack<int> mstack;

    //push(): Adds an element to the top of the stack.
    mstack.push(5);
    mstack.push(17);
    
    //top(): Returns a reference to the top element of the stack without removing it.
    std::cout << mstack.top() << std::endl;

    //pop(): Removes the element from the top of the stack.
    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    std::cout << std::endl;

    /*------------------------------------------------------*/
    std::cout << "\033[38;5;206mUsing std::list\033[0m" << std::endl;
    std::list<int> myList;
    myList.push_back(5);
    myList.push_back(17);    
    std::cout << myList.front() << std::endl;
    myList.pop_front();

    std::cout << myList.size() << std::endl;

    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);

    std::list<int>::iterator it1 = myList.begin();
    std::list<int>::iterator ite2 = myList.end();
    ++it1;
    --it1;

    while (it1 != ite2)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }

    std::stack<int, std::list<int> > s1(myList);    
    return 0;
}
