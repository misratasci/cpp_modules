
#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon() {
	this->type = "Unknown";
}

Weapon::Weapon(std::string type) {
	this->type = type;
}

const std::string &Weapon::getType(void) {
	return (this->type);
}

void Weapon::setType(std::string type) {
	this->type = type;
}