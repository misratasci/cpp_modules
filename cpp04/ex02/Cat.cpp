
#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
    if (!this->brain) {
        std::cerr << "Could not allocate brain for cat" << std::endl;
        exit(1);
    }
    return ;
}

Cat::Cat(Cat const &src) : Animal(src) {
    std::cout << "Cat copy constructor called" << std::endl;
    
    this->type = src.type;
    this->brain = new Brain(*src.brain);
    if (!this->brain) {
        std::cerr << "Could not allocate brain for cat" << std::endl;
        exit(1);
    }
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
    return ;
}

Cat &Cat::operator=(Cat const &src) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this == &src)
        return *this;

    this->type = src.type;
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*src.brain);
    if (!this->brain) {
        std::cerr << "Could not allocate brain for cat" << std::endl;
        exit(1);
    }
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << this->type << " says 'meow'" << std::endl;
}

const std::string Cat::getIdea(int i) const {
    return this->brain->getIdea(i);
}

void Cat::setIdea(int i, std::string idea) {
    this->brain->setIdea(i, idea);
}