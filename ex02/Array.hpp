#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>


# define BOLDWHITE "\e[1;37m"
# define BOLDRED "\e[1;91m"
# define DEFAULT "\x1b[0m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define CYAN 	"\e[0;36m"

template <typename T>
class Array
{
	public:
		Array();
		explicit Array(unsigned int n);
		Array(Array const &src);
		Array &operator=(Array const &other);
		~Array();

		T &operator[](int index);
		T const &operator[](int index) const;

		unsigned int size() const;

	private:
		T *_array;
		unsigned int _size;
};
#include "Array.tpp"


#endif
