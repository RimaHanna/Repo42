// #include <iostream>
// #include <cstdlib>
#include "Span.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printStorage();
	cout << "shortest span: " << sp.shortestSpan() << endl;
	cout << "longest span: " << sp.longestSpan() << endl;

	// Pushing beyond N elements
	try
    {
		sp.addNumber(42);
		std::cout << "A number was added to the span" << std::endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	// Trying to get a span with less than 2 elements on the vector
	Span sp1 = Span(1);
	sp1.addNumber(1);
	try
    {
		cout << sp1.shortestSpan() << endl;
	}
	catch(const std::exception& e)
    {
		cerr << e.what() << '\n';
	}

	Span sp2(11);
	sp2.addNumber(2);
	sp2.addRandomNumbers(10);
	cout << "sp2 ";
	sp2.printStorage();
	cout << "sp2.shortestSpan = " << sp2.shortestSpan() << endl;
	cout << "sp2.longestSpan = " << sp2.longestSpan() << endl;
	return EXIT_SUCCESS;
}