#include <Intern.hpp>

Intern::Intern(void)
{
    std::cout << "\033[36mIntern default constructor called!\033[0m" << std::endl; 
}

Intern::Intern(const Intern &other)
{
    *this = other;
    std::cout << "\033[36mIntern copy constructor called!\033[0m" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    std::cout << "\033[36mIntern copy assignement operator called!\033[0m" << std::endl;
    return *this;
}

Intern::~Intern()
{
	std::cout << "\033[36mIntern default destructor has been called\033[0m" << std::endl;
}

AForm* Intern::makeForm(std::string const &type, std::string const &target)
{
    AForm *aform;
    aform = AForm::makeForm(type, target);
    if (!aform)
        throw (AForm::InvalidFormException());
    else
        std::cout << "\033[36mIntern creates form: \033[0m" << aform->getName() << "\033[36m with target:  \033[0m" << aform->getTarget() << std::endl;
    return aform;
}