
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie *zb_arr = new Zombie[N];

	for (int i = 0; i < N; i++) {
		zb_arr[i].set_name(name);
	}
	return zb_arr;
}