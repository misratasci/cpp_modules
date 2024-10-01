
#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
	this->index = 0;
	this->size = 0;
}

void PhoneBook::add() {
	Contact c;
	c.get_contact();
	this->contacts[this->index] = c;
	this->index++;
	if (this->index >= 8)
		this->index = 0;
	if (this->size < 8)
		this->size++;
}

void PhoneBook::search() {
	int i;
	std::cout << "Index of entry: ";
	std::cin >> i;
	if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Index out of bounds" << std::endl;
		return ;
	}
	if (i - 1 < 0 || i - 1 >= this->size) {
		std::cout << "Index out of bounds" << std::endl;
		return ;
	}
	this->contacts[i - 1].print(i);
}