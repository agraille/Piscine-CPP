#include "easyfind.hpp"

TEMPLATE
typename T::iterator	easyfind(T& container, int value){
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Invalid value");
	return it;
}
