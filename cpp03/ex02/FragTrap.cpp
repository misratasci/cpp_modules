
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap name constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const &src): ClapTrap(src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &src) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " gives a high five to everyone!" << std::endl;
}