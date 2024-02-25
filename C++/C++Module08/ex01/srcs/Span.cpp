#include "Span.hpp"

using std::cout;
using std::endl;

Span::Span(uint32_t N) : max_N(N), storage(0)
{
    // Default constructor
};

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	this->max_N = other.max_N;
	this->storage = other.storage;
	return *this;
}

Span::~Span(void)
{
    // Default destructor
};

void Span::addNumber(int nbr)
{
	if (this->storage.size() == this->max_N)
		throw Span::SpanFullException();
	this->storage.push_back(nbr);
}

void Span::addRandomNumbers(uint32_t quantity)
{
	srand(time(NULL));
	for (uint32_t i = 0; i < quantity; i += 1)
		this->addNumber(rand());
}

int Span::shortestSpan(void)
{
	//  create a local copy of the storage vector using the copy constructor
    std::vector<int> vect = this->storage;

    if (vect.size() < 2)
    {
        throw NoSpanFoundException();
    }

	// sorting the elements in the vect vector in ascending order
    std::sort(vect.begin(), vect.end());

	//  initialize the shortest variable with the maximum possible 
	// integer value using std::numeric_limits<int>::max(). 
	// This ensures that any valid span will be smaller than this initial value.
    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < vect.size(); ++i)
    {
		// abs calculate the absolute difference between them
        int span = std::abs(vect[i] - vect[i - 1]);
        if (span < shortest)
        	shortest = span;
    }
    return shortest;
}

int Span::longestSpan(void)
{
	std::vector<int> vect = this->storage;

	if (vect.size() < 2)
		throw Span::NoSpanFoundException();
		
	int min = *std::min_element(vect.begin(), vect.end());
	int max = *std::max_element(vect.begin(), vect.end());

	return abs(max - min);
}

void Span::printStorage(void)
{
	std::vector<int> vect = this->storage;
	std::vector<int>::iterator i;

	cout << "Storage = ";
	for (i = vect.begin(); i != vect.end(); i += 1)
		cout << *i << " ";
	cout << endl;
}

char const* Span::SpanFullException::what(void) const throw()
{
	return "Span is already full. Cannot add more elements.";
}

char const* Span::NoSpanFoundException ::what(void) const throw()
{
    return "No span found. There are no numbers stored or only one number.";
}