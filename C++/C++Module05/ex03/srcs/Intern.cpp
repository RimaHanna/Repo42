#include <Intern.hpp>

Intern::Intern(void)
{
    std::cout << "Intern default constructor called!" << std::endl; 
}

Intern::Intern(const Intern &other)
{
    *this = other;
    std::cout << "Intern copy constructor called!" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    std::cout << "Intern copy assignement operator called!" << std::endl;
    return *this;
}

Intern::~Intern()
{
	std::cout << "Intern default destructor has been called" << std::endl;
}

AForm* Intern::makeForm(std::string const &type, std::string const &target)
{
    AForm *aform;
    aform = AForm::makeForm(type, target);
    if (!aform)
        throw (AForm::InvalidFormException());
    else
        std::cout << "Intern creates form: " << aform->getName() << " with target: " << aform->getTarget() << std::endl;
    return aform;
}