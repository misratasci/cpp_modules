
#include "Animal.hpp"

Animal::Animal() : type("default") {
    std::cout << "Animal default constructor called" << std::endl;
    return ;
}

Animal::Animal(Animal const &src) {
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = src.type;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

Animal &Animal::operator=(Animal const &src) {
    std::cout << "Animal assignment operator called" << std::endl;
    this->type = src.type;
    return *this;
}

std::string const &Animal::getType(void) const {
    return this->type;
}

void Animal::makeSound(void) const {
    std::cout << this->type << " makes a default sound" << std::endl;
}
