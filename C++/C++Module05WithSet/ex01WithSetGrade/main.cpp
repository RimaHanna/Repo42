#include <cstdlib>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\033[33mGENERAL \033[0m" << std::endl;
	{
		// Constructor
		Form	a("File", 42, 42);
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
		std::cout << "\033[33mTEST 4 \033[0m" << std::endl;
		try {
        Bureaucrat studentR("Roy", 11);
        Form form("exam1", 12, 11);

        studentR.signForm(form);

        std::cout << form << std::endl;
    	} 
		catch (std::exception &e) {
    	    std::cout << e.what() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "\033[33mTEST 5 \033[0m" << std::endl;
		try {
        Bureaucrat studentR("Roy", 11);
        Form form("exam2", 10, 11);

        studentR.signForm(form);

        std::cout << form << std::endl;
    	} 
		catch (std::exception &e) {
    	    std::cout << e.what() << std::endl;
    	}
	}
	return EXIT_SUCCESS;
}
