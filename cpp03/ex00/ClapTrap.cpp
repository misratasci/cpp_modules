
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("default"), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "Name constructor called" << std::endl;
    return ;
}

ClapTrap ClapTrap::operator=(ClapTrap const &src) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->name = src.name;
    this->hit_points = src.hit_points;
    this->energy_points = src.energy_points;
    this->attack_damage = src.attack_damage;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " repairs itself by " << amount << " points!" << std::endl;
    this->hit_points += amount;
    this->energy_points--;
}