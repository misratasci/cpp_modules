
#include "ClapTrap.hpp"

int main() {
    ClapTrap a;
    ClapTrap b("misra");
    ClapTrap c(b);
    a = ClapTrap("ayse");
    a.attack("zeynep");
    b.beRepaired(3);
    c.takeDamage(2);
    a.takeDamage(10);
    a.takeDamage(1);
}
