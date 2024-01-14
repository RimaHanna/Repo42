#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm::AForm("RobotomyRequestForm", 72, 45), _target("null")
{
    std::cout << "RobotomyRequestForm default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm::AForm(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called!" << std::endl;
}

RobotomyRequestForm const	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
    std::cout << "RobotomyRequestForm copy assignement operator called!" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::executed(const Bureaucrat &bureaucrat) const
{
	int	success;

	/* Set Seed */
	// Two seperate functions that initialize and call the generator of random numbers
	srand((unsigned) time(NULL)); // initialize the random generator engine
	success = rand() % 2; // gets a random number form the generator
    std::cout << "\033[36mDrilling noises...\033[0m" << std::endl;
	(void)bureaucrat;
	if (success)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << "'s robotomization failed" << std::endl;
}

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
	return (str << form.getName() << " form, signed: " << (form.getIsSigned() == true ? "yes" : "no") << ", sign grade: " << form.getGradeToSign() << ", exec grade: " << form.getGradeToExecute());
}