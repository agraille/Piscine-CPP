#include "Span.hpp"

Span::Span(uint n) : _n(n){
	_v.reserve(n);
}

Span::Span(const Span& other) : _n(other._n){
	_v.reserve(other._n);
}

Span::~Span(){}

Span& Span::operator=(const Span& other){
    if (this != &other) {
        _n = other._n;
		_v = other._v;
    }
    return *this;
}

void	Span::addNumber(int number){
	if (_v.size() >= _n) {
	    throw std::runtime_error("Span is already full!");
	}
	_v.push_back(number);
}

uint		Span::shortestSpan(){
	if (_v.size() <= 1)
        throw std::runtime_error("Not enough numbers to find a span.");
	std::sort(_v.begin(), _v.end());
	int	min = INT_MAX;
	for (uint i = 0; i < _v.size() - 1; ++i){
		int diff = _v[i + 1] - _v[i];
		if (diff < min)
			min = diff;
	}
	return min;
}

uint		Span::longestSpan(){
	if (_v.size() <= 1)
        throw std::runtime_error("Not enough numbers to find a span.");
	std::sort(_v.begin(), _v.end());
	return *std::prev(_v.end()) - *_v.begin();
}

void 	Span::addRandomNumbers(uint count){
	if (_n < count)
	    throw std::out_of_range("Vector size to small!");
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(INT_MIN, INT_MAX);
	for (uint i = 0; i < count; ++i)
		addNumber(dist(gen));
}
