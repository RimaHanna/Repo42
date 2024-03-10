#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2 )
    {
        std::cerr << "Error: missing arguments" << std::endl;
        return 1;
    }
    std::vector<int> Vec;
    std::deque<int> Deq;
    double vectorSortingTime;
    double dequeSortingTime;
    int number;
    for (int index = 1; index < argc; index++)
    {
        std::stringstream ss(argv[index]); // Enable imput and output on strings
        if (!(ss >> number) || !(ss.eof())) // attemps to extract a number from ss and put it in number and check if we reach the end of
        {
            std::cerr << "Error: invalid arguments" << std::endl;
            return 1;
        }
        if (number < 0)
        {
            std::cerr << "Error: Negative number !" << std::endl;
            return 1;
        }
        Vec.push_back(number);
        Deq.push_back(number);
    }

    std::cout << std::endl;
    printContainerState(Vec, Deq);
    calculateTimeForVector(Vec, vectorSortingTime);
    calculateTimeForDeque(Deq, dequeSortingTime);
    std::cout << std::endl;
    printContainerState(Vec, Deq);
    std::cout << std::endl << "\033[34mTime to process a range of " <<  argc - 1 <<  " elements with std::vector : " << vectorSortingTime << " us" << std::endl;
    std::cout << "Time to process a range of " <<  argc - 1 <<  " elements with std::deque :  " << dequeSortingTime << " us\033[0m" << std::endl;
    return 0;
}