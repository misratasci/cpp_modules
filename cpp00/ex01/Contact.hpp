
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_num;
	std::string secret;
	std::string get_input(std::string prompt);

	public:
	void get_contact();
	void print(int i);
};

#endif