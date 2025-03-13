#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string name;
		int hit_points;
		int energy_points;
		int attack_damage;
	public:
		ClapTrap();
		ClapTrap(ClapTrap const &src);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &src);
		void attack(const std::string& target);
		void takeDamage(int amount);
		void beRepaired(int amount);
};


#endif
