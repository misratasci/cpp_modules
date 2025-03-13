
#include "FragTrap.hpp"

int main() {
    FragTrap a;
    FragTrap b("misra");
    FragTrap c(b);
    a = FragTrap("ayse");
    a.attack("zeynep");
    b.beRepaired(3);
    c.takeDamage(99);
    c.takeDamage(2);
    a.highFivesGuys();
}
