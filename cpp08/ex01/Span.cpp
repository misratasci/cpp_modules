#include "Span.hpp"

Span::Span() : N(0), data() {
}

Span::Span(unsigned int N) : N(N), data() {
}

Span::Span(Span const &src) : N(src.N), data(src.data) {
}

Span &Span::operator=(Span const &src) {
	if (this != &src) {
		this->N = src.N;
		this->data = src.data;
	}
	return *this;
}

Span::~Span() {
}

void Span::addNumber(int value) {
	if (this->data.size() >= this->N)
		throw std::out_of_range("Capacity exceeded");
	this->data.push_back(value);
}

void Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    if (this->data.size() + std::distance(first, last) > this->N)
        throw std::out_of_range("Capacity exceeded");
    this->data.insert(this->data.end(), first, last);
}

int Span::shortestSpan() const {
	if (this->data.size() < 2)
		throw std::runtime_error("Not enough elements for span");
	std::vector<int> tmp = this->data;
	std::sort(tmp.begin(), tmp.end());
	long long minDiff = std::numeric_limits<long long>::max();
	for (size_t i = 1; i < tmp.size(); i++)
	{
		long long diff = static_cast<long long>(tmp[i]) - static_cast<long long>(tmp[i - 1]);
		if (diff < minDiff)
			minDiff = diff;
	}
	return static_cast<int>(minDiff);
}

int Span::longestSpan() const {
	if (this->data.size() < 2)
		throw std::runtime_error("Not enough elements for span");
	std::vector<int> tmp = this->data;
	std::sort(tmp.begin(), tmp.end());
	long long diff = static_cast<long long>(tmp.back()) - static_cast<long long>(tmp.front());
	return static_cast<int>(diff);
}
