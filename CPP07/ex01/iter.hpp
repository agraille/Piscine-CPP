#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T>
void	iter(const T *tab,const int length, void(*f)(T const&))
{
	for (int i = 0; i < length; i++)
		f(tab[i]);

}

#endif
