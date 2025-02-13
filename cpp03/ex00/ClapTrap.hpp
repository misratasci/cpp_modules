#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string name;
		unsigned int hit_points = 10;
		unsigned int energy_points = 10;
		unsigned int attack_damage = 0;
	public:
		ClapTrap();
		ClapTrap(ClapTrap const &src);
		ClapTrap(std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif
