#include <iostream>
#include <string>

int main()
{
	// Variable of type string
	std::string str = "HI THIS IS BRAIN";

	// Pointer to the string
	std::string *stringPTR;
	stringPTR = &str;

	// String reference
	std::string &stringREF = str;

	// Adresses
	std::cout << "Address of the string: "
				<< &str << std::endl; 
	std::cout << "Address in stringPTR:  "
				<< stringPTR << std::endl;
	std::cout << "Address in stringPTR:  "
				<< &stringREF << std::endl;
	// Values
	std::cout << "Value of string:       "
				<< str << std::endl; 
	std::cout << "Value in stringPTR:    "
				<< *stringPTR << std::endl;
	std::cout << "Value in stringREF:    "
				<< stringREF << std::endl;
	return (0);
}