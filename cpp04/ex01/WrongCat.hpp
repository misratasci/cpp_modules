
#ifndef WRONGWrongCat_HPP
# define WRONGWrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		~WrongCat();
		WrongCat &operator=(WrongCat const &src);
        void makeSound(void) const;
};

#endif