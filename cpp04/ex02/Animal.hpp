
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <cstdlib>

class Animal {
	protected:
		std::string type;
		Animal();
	public:
		Animal(Animal const &src);
		virtual ~Animal();
		Animal &operator=(Animal const &src);
        std::string const &getType(void) const;
        virtual void makeSound(void) const = 0;
};

#endif