#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
    public:
        Brain();
        ~Brain();
        Brain (const Brain &other);
        Brain &operator = (const Brain &other);

    // Since Brain* in Cat and Dog is in private mode
    // It is better to make ideas private than public
    // to encapsulates the implementation of the Brain
    // class and ensures that access to the array is c
    // constrolled by weel-defined memeber-function. 
    private:
        std::string ideas[100];
};

#endif // BRAIN_HPP