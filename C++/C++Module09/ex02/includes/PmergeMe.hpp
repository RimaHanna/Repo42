#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream>
#include <cstddef>

#define START(nb) nb + 1

class PmergeMe
{
    public:

        PmergeMe();
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& other);
        PmergeMe(const PmergeMe& other);
        
        //Vector sort
        static void mergeInsertSortVector(std::vector<int> &container, int start, int end);
        static void mergeSortVector(std::vector<int> &container, int start, int mid, int end);
        static void insertSortVector(std::vector<int> &container, int start, int end);
        static void runVector(std::vector<int> &container);

        //Deque sorting
        static void mergeInsertSortDeque(std::deque<int> &container, int start, int end);
        static void mergeSortDeque(std::deque<int> &container, int start, int mid, int end);
        static void insertSortDeque(std::deque<int> &container, int start, int end);
        static void runDeque(std::deque<int> &container);
        
};

// Utility functions
void printContainerState(std::vector<int> &, std::deque<int> &);
void calculateTimeForVector(std::vector<int> &vecContainer, double &vecTime);
void calculateTimeForDeque(std::deque<int> &dequeContainer, double &dequeTime);

#endif