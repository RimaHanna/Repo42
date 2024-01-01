#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

/* When inheriting from a base class to a derived class,
 the derived class does not need to repeat the entire 
 canonical form of the base class. The derived class 
 inherits the constructors, destructor, 
and assignment operators from the base class.
ScavTrap (const ScavTrap &to_copy);
ScavTrap &operator = (const ScavTrap &original); 
*/
/* If C1 inherits publicly from C2 (class C1 : public C2), 
public members of C2 remain public in C1, protected members 
remain protected, and private members of C2 are not accessible in C1.
*/

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ~ScavTrap(void);
        void attack(const std::string& target);
        void guardGate();

    private:
    /* Private constructor serving in a way to prevent the
     creation of Scavtrap witthout a name; */
        ScavTrap(void);

};

#endif