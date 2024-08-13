
#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie zb = Zombie(name);
	zb.announce();
}