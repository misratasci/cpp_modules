
#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < this->len; i++) {
        this->ideas[i] = "default idea";
    }
    return ;
}

Brain::Brain(Brain const &src) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < this->len; i++) {
        this->ideas[i] = src.ideas[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

Brain &Brain::operator=(Brain const &src) {
    std::cout << "Brain assignment operator called" << std::endl;
    for (int i = 0; i < this->len; i++) {
        this->ideas[i] = src.ideas[i];
    }
    return *this;
}

const std::string Brain::getIdea(int i) const {
    if (i > this->len) {
        std::cout << "There are only " << this->len << " ideas in this brain!" << std::endl;
        return "";
    }
    return this->ideas[i];
}

void Brain::setIdea(int i, std::string idea) {
    if (i > this->len) {
        std::cout << "There are only " << this->len << " ideas in this brain!" << std::endl;
        return;
    }
    this->ideas[i] = idea;
}