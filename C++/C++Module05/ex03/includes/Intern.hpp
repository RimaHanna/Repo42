// create forms using the makeForm() function
    // takes two strings as parameters: the name of a form and the target of the form
    // It returns a pointer to a Form object with the specified name and target.
    // The function prints a message like: "Intern creates <form>."
    // If the form name passed as a parameter doesn't exist, it should print an explicit error message.
// create forms when requested from bureaucrats -> er have to call the Intern from the bureaucrat

#ifndef INTERN_HPP
# define INTERN_HPP
#include <iostream>
#include <AForm.hpp>

class AForm;

class Intern
{
    public:
        Intern(void);
        Intern(const Intern &other);
        Intern &operator = (const Intern &other);
        ~Intern(void);

        AForm *makeForm(std::string const &formName, std::string const &target);
};

#endif