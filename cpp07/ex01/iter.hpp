#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter(T *array, const int length, F func) {
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template<typename T, typename F>
void iter(const T *array, const int length, F func) {
    for (int i = 0; i < length; i++)
        func(array[i]);
}

template<typename T>
void func(const T &x) {
    std::cout << x << " ";
}

#endif
