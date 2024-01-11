#include <cstdlib>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\033[33mGENERAL \033[0m" << std::endl;
	{
		// Constructor
		Form	a("Contract", 42, 42);
		// Copy Constructor
		Form	b(a);
		// Copy assignment
		Form	c = b;

		std::cout << std::endl;

		// ostream overload
		std::cout << "a:\n" << a << std::endl;
		std::cout << "b:\n" << b << std::endl;
		std::cout << "c:\n" << c << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "\033[33mTEST 1 \033[0m" << std::endl;
		try
		{
			// Grade too low
			Form	a("A", LOWEST_GRADE + 1, LOWEST_GRADE - 1);
			std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "\033[33mTEST 2 \033[0m" << std::endl;
		try
		{
			// Grade too high
			Form	b("B", HIGHEST_GRADE - 1, 42);
			std::cout << b << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "\033[33mTEST 3 \033[0m" << std::endl;
		try
		{
			// Able to sign all forms
			Bureaucrat	s1("Student1", HIGHEST_GRADE);
			std::cout << s1 << std::endl;

			Form	c1("C1", HIGHEST_GRADE, 2);
			Form	c2("C2", 90, LOWEST_GRADE);
			std::cout << c1 << std::endl;
			std::cout << c2 << std::endl;

			c1.beSigned(s1);
			c2.beSigned(s1);
			c1.beSigned(s1);

			std::cout << c1 << std::endl;
			std::cout << c2 << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "\033[33mTEST 4 \033[0m" << std::endl;
		try
		{
			// Unable to sign any form
			Bureaucrat	s2("Student2", LOWEST_GRADE);
			std::cout << s2 << std::endl;

			Form	c3("C3", HIGHEST_GRADE, 2);
			std::cout << c3 << std::endl;

			// Exception will be thrown
			c3.beSigned(s2);
			std::cout << c3 << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "\033[33mTEST 5 \033[0m" << std::endl;
		try {
        Bureaucrat bureaucrat("Roy",11);
        Form form("exam1", 10, 11);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    	} 
		catch (std::exception &e) {
    	    std::cout << e.what() << std::endl;
    	}
	}
	return EXIT_SUCCESS;
}
