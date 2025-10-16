#include <iostream>
#include "iter.hpp"

int main() {
    int intArr[] = {1, 2, 3};
    const int constIntArr[] = {4, 5, 6};
    double dblArr[] = {1.1, 2.2, 3.3};
    std::string strArr[] = {"a", "b", "c"};

    iter(intArr, 3, func<int>);
    iter(constIntArr, 3, func<const int>);
    iter(dblArr, 3, func<double>);
    iter(strArr, 3, func<std::string>);
    std::cout << std::endl;
    return 0;
}
