#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	// Create the 3 forms and some Bureaucrats 
	std::cout << "\033[33mForm 1: shrubbery \033[0m" << std::endl;
	ShrubberyCreationForm shrubbery("Home");
	std::cout << "\033[33mForm 2: robotomy \033[0m" << std::endl;
	RobotomyRequestForm robotomy("Roby");
	std::cout << "\033[33mForm 3: pardon \033[0m" << std::endl;
	PresidentialPardonForm pardon("Trump");

	std::cout << std::endl;
	std::cout << "\033[33mBureaucrat Rima \033[0m" << std::endl;
	Bureaucrat Rima("Rima", 150);

	std::cout << "\033[33mBureaucrat Roy \033[0m" << std::endl;
	Bureaucrat Roy("Roy", 120);

	std::cout << "\033[33mBureaucrat Oli \033[0m" << std::endl;
	Bureaucrat Oli("Oli", 3);
	
	std::cout << std::endl;	
	std::cout << "\033[38;5;206mTry to execute forms without being signed	\033[0m" << std::endl; 
	{
		try
		{
			std::cout << Rima << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			Rima.executeAForm(shrubbery);
			Rima.executeAForm(robotomy);
			Rima.executeAForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;	
	std::cout << "\033[38;5;206mSign form and try to execute without enough grade	\033[0m" << std::endl; 
	{
		try
		{
			std::cout << Rima << std::endl;
			std::cout << Roy << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			shrubbery.beSigned(Roy);
			Rima.executeAForm(shrubbery);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;	
	std::cout << "\033[38;5;206mSign forms and execute them		\033[0m" << std::endl;  
	{
		try
		{
			std::cout << Oli << std::endl;
			robotomy.beSigned(Oli);
			pardon.beSigned(Oli);
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;
			
			std::cout << "\n --------------------- \n\n";
			Oli.executeAForm(shrubbery);
			std::cout << "\n --------------------- \n\n";
			Oli.executeAForm(robotomy);
			std::cout << "\n --------------------- \n\n";
			Oli.executeAForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;	
	return (0);
}
