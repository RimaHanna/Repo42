#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ~ScavTrap(void);
//        ScavTrap (const ScavTrap &to_copy);
//        ScavTrap &operator = (const ScavTrap &original);
        void attack(const std::string& target);
        void guardGate();

    private:
        // Private constructor serving in a way to prevent the
        // creation of Scavtrap witthout a name;
        ScavTrap(void);

};

#endif