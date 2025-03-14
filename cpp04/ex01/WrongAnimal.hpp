
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal();
		WrongAnimal &operator=(WrongAnimal const &src);
        std::string const &getType(void) const;
        void makeSound(void) const;
};

#endif