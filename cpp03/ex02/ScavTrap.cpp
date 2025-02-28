
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->gate_keeper = false;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->gate_keeper = false;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->gate_keeper = src.gate_keeper;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}


ScavTrap ScavTrap::operator=(ScavTrap const &src) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	this->gate_keeper = src.gate_keeper;
	return *this;
}


void ScavTrap::attack(std::string const &target) {
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_points--;
}


void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in gate keeper mode" << std::endl;
	this->gate_keeper = true;
}