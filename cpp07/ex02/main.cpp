#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); ++i)
        arr[i] = i * 2;
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}
