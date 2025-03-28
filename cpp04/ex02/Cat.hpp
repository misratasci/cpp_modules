
#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain *brain;
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();
		Cat &operator=(Cat const &src);
        void makeSound(void) const;
		const std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
};

#endif