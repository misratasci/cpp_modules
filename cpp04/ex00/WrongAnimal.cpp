
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong default") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = src.type;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
    return ;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    this->type = src.type;
    return *this;
}

std::string const &WrongAnimal::getType(void) const {
    return this->type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << this->type << " makes a wrong default sound" << std::endl;
}
