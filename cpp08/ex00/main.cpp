#include <iostream>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	std::vector<int>::iterator it = easyfind(v, 6);
	std::cout << *it << std::endl;

	try {
		easyfind(v, 15);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
