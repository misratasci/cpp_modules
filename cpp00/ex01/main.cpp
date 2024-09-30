
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
	PhoneBook pb;
	std::string cmd;
	std::cout << "Enter command: ";
	std::cin >> cmd;
	while (cmd.compare("EXIT") != 0) {
		if (cmd.compare("ADD") == 0)
			pb.add();
		if (cmd.compare("SEARCH") == 0)
			pb.search();
		std::cout << "Enter command: ";
		std::cin >> cmd;
	}
	return (0);
}