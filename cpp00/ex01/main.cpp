
#include "PhoneBook.hpp"

int main() {
	PhoneBook pb;
	std::string cmd;
	std::string prompt = "Enter command (ADD, SEARCH or EXIT): ";
	std::cout << prompt;
	std::getline(std::cin, cmd);
	while (cmd.compare("EXIT") != 0) {
		if (cmd.compare("ADD") == 0)
			pb.add();
		if (cmd.compare("SEARCH") == 0)
			pb.search();
		std::cout << prompt;
		std::getline(std::cin, cmd);
	}
	return (0);
}