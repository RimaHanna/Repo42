#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdint.h>
# include <exception>
# include <vector>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <limits>

class Span
{
    private:
		uint32_t max_N;
		std::vector<int> storage;
		Span();

	public:
		Span(uint32_t N);
		Span(const Span &other);
		Span &operator=(const Span& other);
		~Span(void);

		void addNumber(int nbr);
		void addRandomNumbers(uint32_t quantity);
		int shortestSpan(void);
		int longestSpan(void);

		void printStorage(void);

		class SpanFullException  : public std::exception {
			public:
				char const* what() const throw();
		};
		
		class NoSpanFoundException  : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif // SPAN_HPP