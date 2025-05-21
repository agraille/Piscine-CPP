#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

# define RED        "\033[31m"
# define GREEN        "\033[32m"
# define YELLOW        "\033[33m"
# define BLUE        "\033[34m"
# define PURPLE        "\033[35m"
# define CYAN        "\033[36m"
# define WHITE        "\033[37m"
# define RESET        "\033[0m"

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
