
#include "ClapTrap.hpp"

int main() {
    ClapTrap a;
    ClapTrap b("misra");
    ClapTrap c(b);
    a = ClapTrap("ayse");
    a.attack("zeynep");
    b.beRepaired(3);
    c.takeDamage(2);
}
