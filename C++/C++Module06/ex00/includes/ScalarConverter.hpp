#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <limits>   // For numeric limits
#include <cmath>    // For mathematical functions and special values
#include <iostream> // For input/output (if needed)
#include <cstdlib> // For std::strtof, std::strtod
#include <climits> // For INT_MAX, INT_MIN
#include <cfloat>  // For FLT_MAX, FLT_MIN, isnan
#include <cstdlib> // For std::strtol, std::strtod
#include <cctype>  // For isprint
#include <cstring> // For strcpy
#include <sstream> // For stringstream
/**
 * Static methods in C++ are class-level functions that do not require
 * an instance of the class for invocation. They are associated with the
 * class rather than individual objects, lack access to instance-specific
 * members, and are called using the class name. Static methods are 
 * commonly used for operations independent of object state, such as 
 * utility functions or managing shared class-level data.
*/


// REMARKS:
// class should not be instantiated by users

class ScalarConverter
{
	private:
		/* Constructors & Destructors */
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter(void);
		
		/* Basic Operators */
		ScalarConverter &operator = (const ScalarConverter &other);

	public:
		/* Static method */
		static void convert(const std::string& literal);
};

#endif // SCALARCONVERTER_HPP

