
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void Contact::get_contact() {
	std::cout << "First name: ";
	std::cin >> this->first_name;
	std::cout << "Last name: ";
	std::cin >> this->last_name;
	std::cout << "Nickname: ";
	std::cin >> this->nickname;
	std::cout << "Phone number: ";
	std::cin >> this->phone_num;
	std::cout << "Darkest secret: ";
	std::cin >> this->secret;
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
