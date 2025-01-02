
#include "Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed(): value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const num) {
	std::cout << "Int constructor called" << std::endl;
	this->value = num << this->fractional_bits;
}

Fixed::Fixed(float const flo) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(flo * (1 << fractional_bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = obj.value;
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat() const {
	return (float)this->value / (float)(1 << fractional_bits);
}

int Fixed::toInt() const {
	return this->value >> fractional_bits;
}

std::ostream& operator<<(std::ostream& o, Fixed const &obj) {
	o << obj.toFloat();
	return o;
}