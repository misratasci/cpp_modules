
#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << name << " is being destroyed\n";
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ\n";
}
