
#include "ScavTrap.hpp"

int main() {
    ScavTrap a;
    ScavTrap b("misra");
    ScavTrap c(b);
    a = ScavTrap("ayse");
    a.attack("zeynep");
    b.beRepaired(3);
    c.takeDamage(99);
    c.takeDamage(2);
    a.guardGate();
    a.guardGate();
}
