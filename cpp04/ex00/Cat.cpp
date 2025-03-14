
#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    return ;
}

Cat::Cat(Cat const &src) : Animal(src) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = src.type;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

Cat &Cat::operator=(Cat const &src) {
    std::cout << "Cat assignment operator called" << std::endl;
    this->type = src.type;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << this->type << " says 'meow'" << std::endl;
}