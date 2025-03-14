
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal *arr[4];
    for (int i = 0; i < 4; i++) {
        if (i < 2) {
            arr[i] = new Dog();
            if (!arr[i]) {
                std::cerr << "Could not allocate Dog" << std::endl;
                return (1);
            }
        }
        else {
            arr[i] = new Cat();
            if (!arr[i]) {
                std::cerr << "Could not allocate Cat" << std::endl;
                return (1);
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        std::cout << "Type: " << arr[i]->getType() << std::endl;
        arr[i]->makeSound();
    }

    for (int i = 0; i < 4; i++) {
        delete arr[i];
    }

    Cat *a = new Cat();
    if (!a) {
        std::cerr << "Could not allocate Cat" << std::endl;
        return (1);
    }

    for (int i = 0; i < 3; i++) {
        a->setIdea(i, "meoww");
    }

    Cat *b = new Cat(*a);
    if (!b) {
        std::cerr << "Could not allocate Cat" << std::endl;
        return (1);
    }

    delete a;

    for (int i = 0; i < 3; i++) {
        std::cout << b->getIdea(i) << std::endl;
    }

    delete b;
}