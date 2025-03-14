
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "Wrong Cat";
    return ;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = src.type;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
    return ;
}

WrongCat &WrongCat::operator=(WrongCat const &src) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    this->type = src.type;
    return *this;
}

void WrongCat::makeSound(void) const {
    std::cout << this->type << " says 'moew'" << std::endl;
}