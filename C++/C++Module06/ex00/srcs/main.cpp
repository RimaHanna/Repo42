#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[31mPlease provide only one argument\033[0m" << std::endl;
		return EXIT_FAILURE;
	}
	std::string literal = argv[1];

	ScalarConverter::convert(literal);
	return EXIT_SUCCESS;
}