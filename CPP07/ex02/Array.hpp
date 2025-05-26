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

		Array&	operator=(const Array& other) {
			if (this != &other) {
				delete[] _type;
				_n = other._n;
				_type = new T[_n];
				for (unsigned int i = 0; i < _n; ++i)
					_type[i] = other._type[i];
			}
			return *this;
		}

		T& operator[](int i) {
			if (i < 0 || static_cast<unsigned int>(i) >= _n)
				throw std::out_of_range("Index out of range");
			return _type[i];
		}

		const T& operator[](int i) const {
			if (i < 0 || static_cast<unsigned int>(i) >= _n)
				throw std::out_of_range("Index out of range");
			return _type[i];
		}

		unsigned int size() const {
			return _n;
		}

	private:
		unsigned int	_n;
		T				*_type;
};

TEMPLATE
std::ostream& operator<<(std::ostream& o, const Array<T>& array){
	for (unsigned int i = 0; i < array.size(); ++i)
		o << array[i] << " ";
	return o;
}

#endif
