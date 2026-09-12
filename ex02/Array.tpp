template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const &src) : _array(new T[src._size]()), _size(src._size)
{
	for (unsigned int i = 0; i < _size; ++i)
		_array[i] = src._array[i];
}


//alors la important il faut faire une DEEEEEEEP copy en gros 
template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		T *tmp = new T[other._size]();

		for (unsigned int i = 0; i < other._size; ++i)
			tmp[i] = other._array[i];
		delete[] _array;
		_array = tmp;
		_size = other._size;
	}
	return (*this);
}


//mais raphael comment ce fait til que tu peux juste ecrire delete[] sans avoir a parse a travers
//le _array ???
//eh bien parceque quand on a fait new T[n], c++ stock automatiquement le nombre delements dans _array
//pour delete !!! donc pas besoin bon en vrai et voila donc en gros cest un free qui automatiquemnet a travers
// ce destructor est appele sur chaque element
template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}


//merci jan pour lavertissement sur ces WARNINGS pour ces overload doperator
//jai failli fumble et pas mettre de check .z.
template <typename T>
T &Array<T>::operator[](int index)
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw std::out_of_range("Array: index out of range");
	return (_array[index]);
}

template <typename T>
T const &Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw std::out_of_range("Array: index out of range");
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}
