#include <iostream>
#include "Array.hpp"

int main() {
    Array<double> doubleArr(3);
    for (unsigned int i = 0; i < doubleArr.size(); i++) {
        doubleArr[i] = i + 0.5;
        std::cout << doubleArr[i] << " ";
    }
    std::cout << std::endl;

    Array<int> intArr(5);
    Array<int> copyArr(intArr);
    for (unsigned int i = 0; i < intArr.size(); i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    for (unsigned int i = 0; i < copyArr.size(); i++) {
        copyArr[i] = i;
        std::cout << copyArr[i] << " ";
    }
    std::cout << std::endl;

    try {
        std::cout << intArr[10] << std::endl;
    } catch (const std::out_of_range &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}
