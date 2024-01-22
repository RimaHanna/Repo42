#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern		rima;
	AForm		*form;
	Bureaucrat	Roy("Roy", 50);

	std::cout << "\033[33mTest 1 all forms are created properly except for the last one\033[0m" << std::endl;
	try
	{
		form = rima.makeForm("robotomy request", "Annah");
		delete form;
		form = rima.makeForm("shrubbery creation", "Celia");
		delete form;
		form = rima.makeForm("presidential pardon", "Dany");
		delete form;
		form = rima.makeForm("random request", "Clay");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[31mCaught exception: \033[0m" << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[33mTest 2: test some Actions with available form \033[0m"<< std::endl;
	form = rima.makeForm("shrubbery creation", "Fred");
	form->beSigned(Roy);
	Roy.executeAForm(*form);
	delete form;

	std::cout << std::endl;
	form = rima.makeForm("presidential pardon", "Georgia");
	Roy.signAForm(*form);
	Roy.executeAForm(*form);
	delete form;
	return (0);
}