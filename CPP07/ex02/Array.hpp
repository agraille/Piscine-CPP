#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
template <typename T>
class Array
{
public:
	Array(): _data(NULL), _size(0) {};
	Array(unsigned int n): _data(new T[n]), _size(n) {};
	Array(const Array &src) : _data(NULL), _size(0) {*this = src;};
	~Array() {delete[] _data;};

	Array &operator=(const Array &src)
	{
		if (this != &src)
		{
			 if (_data != NULL)
			 	delete[] _data;
			_size = src._size;
			_data = new T[src._size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = src._data[i];
		}
		return (*this);
	}

	T &operator[](unsigned int i)
	{
		if (i >= _size)
			throw std::out_of_range("Index out of range");
		return _data[i];
	}

	const T &operator[](unsigned int i) const
	{
		if (i >= _size)
			throw std::out_of_range("Index out of range");
		return _data[i];
	}
	unsigned int size() const {return _size;};

private:
	T				*_data;
	unsigned int	_size;
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const Array<T>& array){
	for (unsigned int i = 0; i < array.size(); ++i)
		o << array[i] << " ";
	return o;
}

#endif
