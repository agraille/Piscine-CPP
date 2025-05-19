#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T ,typename F>
void	iter(T *tab,const int length, void(*f)(F&))
{
	for (int i = 0; i < length; i++)
		f(tab[i]);

}

template< typename T >
void print( T const & x ){
	std::cout << x << "\n";
}

#endif
