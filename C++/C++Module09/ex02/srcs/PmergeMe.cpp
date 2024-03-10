#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::~PmergeMe()
{
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this == &other) {
        return *this; 
    }
    return *this;
}
PmergeMe::PmergeMe(const PmergeMe& other)
{
    (void)(other);
}

//-----------------------------------------Vector sorting-----------------------------------------

void PmergeMe::mergeInsertSortVector(std::vector<int> &container, int start, int end)
{
    int newEnd;
    if (start < end)
    {
        if ((end - start) < 10)
        {
            insertSortVector(container, start, end);
        }
        else
        {
            newEnd = start + (end - start) / 2; // recursively dividing the vector into two halfs
            mergeInsertSortVector(container,  start, newEnd); // sorting to the left half of the current range
            mergeInsertSortVector(container, START(newEnd), end); // sorting to the right half of the current range
            mergeSortVector(container, start, newEnd, end); // merging the two sorted halves 
        }
    }
};

void PmergeMe::mergeSortVector(std::vector<int> &container, int start, int mid, int end)
{
    int i, j , k;

    std::vector<int> left(mid - start + 1);
    std::vector<int> right(end - mid);

    for(i = 0; i < (mid - start + 1); ++i)
        left[i] = container[start + i];
    for(j = 0; j < (end - mid); ++j)
        right[j] = container[mid + 1 + j];
    i = 0;
    j = 0;
    k = start;
    while(i < (mid - start + 1) && j < (end - mid))
    {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while(i < (mid - start + 1))
        container[k++] =  left[i++];
    while (j < (end - mid))
        container[k++] = right[j++];
};

// Sorting the vector within the specified range using the insertion sort algorithm
void PmergeMe::insertSortVector(std::vector<int> &container, int start, int end)
{
    for(int index = START(start); index <= end; index++)
    {
        int hold = container[index];
        int j = index - 1;
        for(; j >= start && container[j] > hold; --j) // moving elements one position to the right to make room for "hold" in the sorted sequence
            container[j + 1] = container[j];
        container[j + 1] = hold;
    }
};

void PmergeMe::runVector(std::vector<int> &container)
{
    mergeInsertSortVector(container, 0, container.size() - 1);
};


//-----------------------------------------Deque sorting -----------------------------------------
void PmergeMe::mergeInsertSortDeque(std::deque<int> &container, int start, int end)
{
    int newEnd;
    if (start < end)
    {
        if ((end - start) < 10)
            insertSortDeque(container, start, end);
        else
        {
            newEnd = start + (end - start) / 2;
            mergeInsertSortDeque(container,  start, newEnd);
            mergeInsertSortDeque(container, START(newEnd), end);
            mergeSortDeque(container, start, newEnd, end);
        }
    }
};

void PmergeMe::mergeSortDeque(std::deque<int> &container, int start, int mid, int end)
{
    int i, j , k;

    std::deque<int> left(mid - start + 1);
    std::deque<int> right(end - mid);

    for(i = 0; i < (mid - start + 1); ++i)
        left[i] = container[start + i];
    for(j = 0; j < (end - mid); ++j)
        right[j] = container[mid + 1 + j];
    i = 0;
    j = 0;
    k = start;
    while(i < (mid - start + 1) && j < (end - mid))
    {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while(i < (mid - start + 1))
        container[k++] =  left[i++];
    while (j < (end - mid))
        container[k++] = right[j++];
};

void PmergeMe::insertSortDeque(std::deque<int> &container, int start, int end)
{
    for(int index = START(start); index <= end; index++)
    {
        int hold = container[index];
        int j = index - 1;
        for(; j >= start && container[j] > hold; --j)
            container[j + 1] = container[j];
        container[j + 1] = hold;
    }
};

void PmergeMe::runDeque(std::deque<int> &container)
{
    mergeInsertSortDeque(container, 0, container.size() - 1);
};

//------------------------------Utility functions ---------------------------------

void calculateTimeForVector(std::vector<int> &vecContainer, double &vecTime)
{
    std::clock_t start = std::clock(); // Start measuring time
    PmergeMe::runVector(vecContainer); // Run sorting algorithm for vector container
    std::clock_t end = std::clock(); // End measuring time
    double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0); // Calculate elapsed time
    vecTime = elapsed; // Store elapsed time for vector sorting
}

void calculateTimeForDeque(std::deque<int> &dequeContainer, double &dequeTime)
{
    std::clock_t start = std::clock(); // Start measuring time
    PmergeMe::runDeque(dequeContainer); // Run sorting algorithm for deque container
    std::clock_t end = std::clock(); // End measuring time
    double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0); // Calculate elapsed time
    dequeTime = elapsed; // Store elapsed time for deque sorting
}


void printContainerState(std::vector<int> &Vec, std::deque<int> &Deq)
{
    static bool isFirstCall = true;

    std::cout << (isFirstCall ? "\033[36mVector before: " : "\033[36mVector after: ");
    for (size_t i = 0; i < Vec.size(); ++i)
        std::cout << Vec[i] << " ";
    std::cout << std::endl;

    std::cout << (isFirstCall ? "\e[0;35mDeque before: " : "\e[0;35mDeque after : ");
    for (size_t i = 0; i < Deq.size(); ++i)
        std::cout << Deq[i] << " ";
    std::cout << std::endl;

    isFirstCall = false;
}
