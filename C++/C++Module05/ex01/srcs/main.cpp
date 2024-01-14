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
		std::cout << "1" << std::endl;
		Form	b(a);

		std::cout << "2" << std::endl;
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
			Form	a("A", 150 + 1, 150 - 1);
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
			Form	b("B", 1 - 1, 42);
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

/*
int main(void)
{
	// Create a form with grade too high 
	{
		try
		{
			Form form0("A99", 0, 5);
			std::cout << form0 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	std::cout << "\n --------------------- \n\n";

	// Create form and sign it without exceptions
	{
		try
		{
			Bureaucrat mike("Mike", 15);
			Form form("B58", 20, 45);
			std::cout << mike << std::endl;
			std::cout << form << std::endl;
			mike.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n --------------------- \n\n";

	// Create form and try to sign it but the grade is not enough 
	{
		try
		{
			Bureaucrat jon("Jon", 35);
			Form form2("C_303", 20, 45);
			std::cout << jon << std::endl;
			std::cout << form2 << std::endl;
			jon.signForm(form2);
			std::cout << form2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
*/