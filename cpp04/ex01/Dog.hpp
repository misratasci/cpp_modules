
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain *brain;
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();
		Dog &operator=(Dog const &src);
        void makeSound(void) const;
		const std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
};

#endif