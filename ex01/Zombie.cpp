
#include "Zombie.hpp"

Zombie::Zombie() {
	name = "Unnamed Zombie";
	std::cout << "An unnamed zombie is created with the default constructor\n";
}

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << name << " is being created\n";
}

Zombie::~Zombie() {
	std::cout << name << " is being destroyed\n";
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ\n";
}