#include <iostream>
#include "Span.hpp"

int main()
{
	try {
		Span sp(5);
		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(9);
		sp.addNumber(6);
		sp.addNumber(8);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		unsigned int M = 20000;
		Span bigsp(M);
		std::vector<int> arr;
		for (int i = 0; i < 15000; i++) {
			arr.push_back(i * 3);
		}
		bigsp.addNumbers(arr.begin(), arr.end());
		std::cout << "Shortest: " << bigsp.shortestSpan() << std::endl;
		std::cout << "Longest: " << bigsp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
