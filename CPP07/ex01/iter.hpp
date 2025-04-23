#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T>
void	iter(T *tab,const int length, void(*f)(T const&))
{
	for (int i = 0; i < length; i++)
		f(tab[i]);

}

template <typename T>
void	iter(T *tab,const int length, void(*f)(T&))
{
	for (int i = 0; i < length; i++)
		f(tab[i]);

}
#endif
