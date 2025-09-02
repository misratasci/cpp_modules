
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* wa = new WrongAnimal();
const WrongAnimal* wc = new WrongCat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << wa->getType() << " " << std::endl;
std::cout << wc->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
wa->makeSound();
wc->makeSound();
meta->makeSound();

delete i;
delete j;
delete meta;
delete wa;
delete wc;

return 0;
}