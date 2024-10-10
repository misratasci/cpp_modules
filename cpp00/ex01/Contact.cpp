
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

std::string Contact::get_input(std::string prompt) {
	std::string input;

	std::cout << prompt;
	std::getline(std::cin, input);
	while (input.empty()) {
		std::cout << "Fields cannot be empty. Try again." << std::endl;
		std::cout << prompt;
		std::getline(std::cin, input);
	}
	return (input);
}

void Contact::get_contact() {
	this->first_name = this->get_input("First name: ");
	this->last_name = this->get_input("Last name: ");
	this->nickname = this->get_input("Nickname: ");
	this->phone_num = this->get_input("Phone number: ");
	this->secret = this->get_input("Darkest secret: ");
}

void Contact::print(int i) {
	std::cout << std::setw(10);
	std::cout << i << "|";
	std::cout << std::setw(10);
	if (this->first_name.size() > 10)
		std::cout << this->first_name.substr(0, 9) << "." << "|";
	else
		std::cout << this->first_name << "|";
	std::cout << std::setw(10);
	if (this->last_name.size() > 10)
		std::cout << this->last_name.substr(0, 9) << "." << "|";
	else
		std::cout << this->last_name << "|";
	std::cout << std::setw(10);
	if (this->nickname.size() > 10)
		std::cout << this->nickname.substr(0, 9) << "." << std::endl;
	else
		std::cout << this->nickname << std::endl;
}
