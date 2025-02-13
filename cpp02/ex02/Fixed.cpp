
#include "Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed(): value(0) {
	return ;
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed::Fixed(int const num) {
	this->value = num << this->fractional_bits;
}

Fixed::Fixed(float const flo) {
	this->value = roundf(flo * (1 << fractional_bits));
}

Fixed::~Fixed() {
	return ;
}

Fixed& Fixed::operator=(Fixed const &obj) {
	this->value = obj.value;
	return *this;
}

int Fixed::getRawBits() const {
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

bool Fixed::operator>(Fixed const obj) {
	return (this->toFloat() > obj.toFloat());
}

bool Fixed::operator<(Fixed const obj) {
	return (this->toFloat() < obj.toFloat());
}

bool Fixed::operator>=(Fixed const obj) {
	return (this->toFloat() >= obj.toFloat());
}

bool Fixed::operator<=(Fixed const obj) {
	return (this->toFloat() <= obj.toFloat());
}

bool Fixed::operator==(Fixed const obj) {
	return (this->toFloat() == obj.toFloat());
}

bool Fixed::operator!=(Fixed const obj) {
	return (this->toFloat() != obj.toFloat());
}

float Fixed::operator+(Fixed const obj) {
	return (this->toFloat() + obj.toFloat());
}

float Fixed::operator-(Fixed const obj) {
	return (this->toFloat() - obj.toFloat());
}

float Fixed::operator*(Fixed const obj) {
	return (this->toFloat() * obj.toFloat());
}

float Fixed::operator/(Fixed const obj) {
	return (this->toFloat() / obj.toFloat());
}

Fixed Fixed::operator++() {
	this->value++;
	return (*this);
}

Fixed Fixed::operator--() {
	this->value--;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++this->value;
	return (temp);
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--this->value;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

std::ostream& operator<<(std::ostream& o, Fixed const &obj) {
	o << obj.toFloat();
	return o;
}