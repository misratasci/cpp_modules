
#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
    if (!this->brain) {
        std::cerr << "Could not allocate brain for Dog" << std::endl;
        exit(1);
    }
    return ;
}

Dog::Dog(Dog const &src) : Animal(src) {
    std::cout << "Dog copy constructor called" << std::endl;
    
    this->type = src.type;
    this->brain = new Brain(*src.brain);
    if (!this->brain) {
        std::cerr << "Could not allocate brain for Dog" << std::endl;
        exit(1);
    }
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
    return ;
}

Dog &Dog::operator=(Dog const &src) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this == &src)
        return *this;

    this->type = src.type;
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*src.brain);
    if (!this->brain) {
        std::cerr << "Could not allocate brain for Dog" << std::endl;
        exit(1);
    }
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << this->type << " says 'woof'" << std::endl;
}

const std::string Dog::getIdea(int i) const {
    return this->brain->getIdea(i);
}

void Dog::setIdea(int i, std::string idea) {
    this->brain->setIdea(i, idea);
}