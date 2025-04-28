#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <exception>

class Span{

	public:
		Span(uint n);
    	Span(const Span& other);
    	~Span();

		Span& operator=(const Span& other);

		void	addNumber(int number);
		uint		shortestSpan();
		uint		longestSpan();
		void 	addRandomNumbers(uint count);


	private:
		std::vector<int>	_v;
    	uint				_n;
};

#endif
