
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = nullptr;
}

void HumanB::attack() {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}