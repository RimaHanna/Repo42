#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

/* When inheriting from a base class to a derived class,
 the derived class does not need to repeat the entire 
 canonical form of the base class. The derived class 
 inherits the constructors, destructor, 
and assignment operators from the base class.
FragTrap (const FragTrap &to_copy);
FragTrap &operator = (const FragTrap &original); 
*/

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        ~FragTrap(void);
        void highFivesGuys();

    private:
        FragTrap(void);

};

#endif // FRAGTRAP_HPP