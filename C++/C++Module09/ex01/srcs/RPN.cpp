#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(std::stack<double> number)
{
	this->numbers = number;
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	this->numbers = other.numbers;
	return (*this); 
}

RPN::~RPN()
{

}

void RPN::calculate(std::string input)
{
    for (size_t i = 0; i < input.size(); ++i)
	{
        char c = input[i];
        if (isspace(c))
		{
            continue;
        }
		else if (isdigit(c))
		{
            numbers.push(c - '0');
        }
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
            if (numbers.size() < 2)
			{
                std::cout << "Invalid input." << std::endl;
                return;
            }
            double b = numbers.top();
            numbers.pop();
            double a = numbers.top();
            numbers.pop();
            switch (c)
			{
                case '+': numbers.push(a + b); break;
                case '-': numbers.push(a - b); break;
                case '*': numbers.push(a * b); break;
                case '/': numbers.push(a / b); break;
            }
        }
		else
		{
            std::cout << "Invalid input." << std::endl;
            return;
        }
    }

    if (numbers.size() == 1)
	{
        std::cout << "Result: " << numbers.top() << std::endl;
        numbers.pop();
    }
	else
	{
        std::cout << "Invalid input." << std::endl;
    }
}
