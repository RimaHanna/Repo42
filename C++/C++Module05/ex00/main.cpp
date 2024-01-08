#include "Bureaucrat.hpp"

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

int main(void)
{
std::cout << "\033[33mGENERAL\033[0m" << std::endl;
	{
		// Constructor
		Bureaucrat	a("RIMA", 87);
		// Copy Constructor
		Bureaucrat	b(a);
		// Copy assignment
		Bureaucrat	c = b;

		// ostream overload
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "\033[33mTEST 1\033[0m" << std::endl;
		try
		{
			// grade too low
			Bureaucrat	a("A", LOWEST_GRADE + 1);
			std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "\033[33mTEST 2\033[0m" << std::endl;
		try
		{
			// grade too high
			Bureaucrat	b("B", HIGHEST_GRADE - 1);
			std::cout << b << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "\033[33mTEST 3\033[0m" << std::endl;
		try
		{
			// Increment to a grade higher than HIGHEST_GRADE
			Bureaucrat	c("C", HIGHEST_GRADE);

			c.incrementGrade();
			std::cout << c << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "\033[33mTEST 4\033[0m" << std::endl;
		try
		{
			// Decrement to a grade lower than LOWEST_GRADE
			Bureaucrat	d("D", LOWEST_GRADE);

			d.decrementGrade();
			std::cout << d << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "\033[33mTEST 5\033[0m" << std::endl;
		try 
		{
			// Acceptable grade changes
			Bureaucrat	bullshit("BULLSHIT", 10);

			bullshit.decrementGrade();
			std::cout << bullshit << std::endl;
			bullshit.incrementGrade();
			std::cout << bullshit << std::endl;
            bullshit.setGrade(160);
            std::cout << bullshit << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return EXIT_SUCCESS;
}