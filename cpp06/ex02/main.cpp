#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  std::srand(std::time(NULL));
  int random = std::rand() % 3;

  if (random == 0) {
    std::cout << "Generated A" << std::endl;
    return new A();
  } else if (random == 1) {
    std::cout << "Generated B" << std::endl;
    return new B();
  } else if (random == 2) {
    std::cout << "Generated C" << std::endl;
    return new C();
  } else {
    return NULL;
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;
    return;
  } catch (std::exception &e) {
  }

  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B" << std::endl;
    return;
  } catch (std::exception &e) {
  }

  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C" << std::endl;
    return;
  } catch (std::exception &e) {
  }

  std::cout << "Unknown type" << std::endl;
}

int main() {
  Base *ptr = generate();

  std::cout << "ptr: ";
  identify(ptr);

  std::cout << "ptr: ";
  identify(*ptr);

  delete ptr;

  return 0;
}
