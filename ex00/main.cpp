
#include "Zombie.hpp"

int main() {
	Zombie *zb = newZombie("misra");
	zb->announce();
	delete zb;
	randomChump("tanhan");
}