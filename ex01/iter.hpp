#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>

# define BOLDWHITE "\e[1;37m"
# define BOLDRED "\e[1;91m"
# define DEFAULT "\x1b[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define CYAN 	"\e[0;36m"



//ce template prends deux value ouah !!!
//ptit truc interessant cest que quand on lui passe un const tel que int const[x]
//eh bah larray i est de type const duh
//mais dcp f ne peut pas etre appele, donc f ne peut pas demander int&
template <typename T, typename F>
void iter(T *array, size_t const size, F f)
{
	for (size_t i = 0; i < size; ++i)
		f(array[i]);
}

#endif
