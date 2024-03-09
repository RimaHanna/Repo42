#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<double> numbers;
	public:
		RPN();
		RPN(std::stack<double> number);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		void calculate(std::string input);
};

#endif //RPNN_HPP