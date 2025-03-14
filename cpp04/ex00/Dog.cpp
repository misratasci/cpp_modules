
#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    return ;
}

Dog::Dog(Dog const &src) : Animal(src) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = src.type;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    return ;
}

Dog &Dog::operator=(Dog const &src) {
    std::cout << "Dog assignment operator called" << std::endl;
    this->type = src.type;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << this->type << " says 'woof'" << std::endl;
}