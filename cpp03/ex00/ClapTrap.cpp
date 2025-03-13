
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("default"), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
    std::cout << "Copy constructor called" << std::endl;
    this->name = src.name;
    this->hit_points = src.hit_points;
    this->energy_points = src.energy_points;
    this->attack_damage = src.attack_damage;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "Name constructor called" << std::endl;
    return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src) {
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
    if (this->energy_points <= 0) {
        std::cout << "ClapTrap does not have enough energy points to attack " << target << "!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hit_points <= 0) {
        std::cout << "ClapTrap already has no hit points left!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    this->hit_points -= amount;
    if (this->hit_points <= 0) {
        std::cout << "ClapTrap is dead!" << std::endl;
        return ;
    }
    std::cout << "It has " << this->hit_points << " hit points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energy_points <= 0) {
        std::cout << "ClapTrap does not have enough energy points to repair itself! " << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " repairs itself by " << amount << " points!" << std::endl;
    this->hit_points += amount;
    std::cout << "It currently has " << this->hit_points << " hit points" << std::endl;
    this->energy_points--;
}