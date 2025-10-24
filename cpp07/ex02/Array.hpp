#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
    T *data;
    unsigned int len;
public:
    Array(): data(new T[0]), len(0) {}
    Array(unsigned int n): data(new T[n]), len(n) {
        for (unsigned int i = 0; i < len; ++i)
            data[i] = T();
    }
    Array(const Array &src): data(new T[src.len]), len(src.len) {
        for (unsigned int i = 0; i < len; ++i)
            data[i] = src.data[i];
    }
    ~Array() {delete[] data;}
    Array &operator=(const Array &src) {
        if (this != &src) {
            delete[] data;
            len = src.len;
            data = new T[len];
            for (unsigned int i = 0; i < len; ++i)
                data[i] = src.data[i];
        }
        return *this;
    }
    T &operator[](unsigned int i) {
        if (i >= len)
            throw std::out_of_range("Index out of range");
        return data[i];
    }
    const T &operator[](unsigned int i) const {
        if (i >= len)
            throw std::out_of_range("Index out of range");
        return data[i];
    }
    unsigned int size() const {
        return len;
    }
};

#endif
