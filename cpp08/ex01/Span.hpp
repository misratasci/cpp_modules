#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span {
private:
	unsigned int N;
	std::vector<int> data;
public:
	Span();
	Span(unsigned int N);
	Span(Span const &src);
	Span &operator=(Span const &src);
	~Span();
	void addNumber(int value);
	void addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);
	int shortestSpan() const;
	int longestSpan() const;
};

#endif
