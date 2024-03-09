#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
    {
        std::cerr << "Error: " << "invalid number of arguments" << '\n';    
        return 1;
    }

    std::string input = argv[1];
    RPN calculator;
    calculator.calculate(input);
    return 0;
}