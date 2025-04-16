#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

#define TEMPLATE template <typename T>

TEMPLATE
class	Array{
	public:
		Array() : _n(0), _type(new T[0]) {}
		Array(unsigned int n) : _n(n), _type(new T[n]){}
		Array(Array<T> const& copy) : _n(copy._n){
			_type = new T[_n];
			for (unsigned int i = 0; i < _n; ++i)
				_type[i] = copy._type[i];
		}
		~Array(){delete[] _type;}

		Array& 			operator=(const Array& other);
		T&				operator[](const unsigned int& i) const;
		unsigned int	size() const;

	private:
		unsigned int	_n;
		T				*_type;
};

TEMPLATE
T&	Array<T>::operator[](const unsigned int& i) const{
	if (i >= _n || i < 0)
		throw	std::out_of_range("OUT OF nRANGE");
	return _type[i];
}

TEMPLATE
std::ostream& operator<<(std::ostream& o, const Array<T>& array){
	for (unsigned int i = 0; i < array.size(); ++i)
		o << array[i] << " ";
	return o;
}

TEMPLATE
unsigned int Array<T>::size() const {
	return _n;
}

TEMPLATE
Array<T>&	Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _type;
		_n = other._n;
		_type = new T[_n];
		for (unsigned int i = 0; i < _n; ++i)
			_type[i] = other._type[i];
	}
	return *this;
}

#endif
