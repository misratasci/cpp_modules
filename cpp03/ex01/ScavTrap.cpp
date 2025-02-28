
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}


ScavTrap ScavTrap::operator=(ScavTrap const &src) {

}


void ScavTrap::attack(std::string const &target) {

}


void ScavTrap::guardGate() {

}