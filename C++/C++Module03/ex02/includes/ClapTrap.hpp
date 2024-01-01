#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
    protected:
        std::string name;
        unsigned hit_points;
        unsigned energy_points;
        unsigned attack_damage;

    public:
        ClapTrap(std::string name);
        ~ClapTrap(void);
        ClapTrap(const ClapTrap &to_copy);
        ClapTrap &operator = (const ClapTrap &other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif //CLAPTRAP_HPP