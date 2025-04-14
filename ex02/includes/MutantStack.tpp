#include "../includes/MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &m){
	*this = src;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &m){
	c = m.c; //c is a protected container from std::stack
	return (*this);
}
// iterator
template <typename T>
MutantStack<T>::iterator	MutantStack<T>::begin(){return (c.begin());}

template <typename T>
MutantStack<T>::iterator	MutantStack<T>::end(){return (c.end());}

// const
template <typename T>
MutantStack<T>::const_iterator	MutantStack<T>::begin() const {return (c.begin());}

template <typename T>
MutantStack<T>::const_iterator	MutantStack<T>::end() const {return (c.end());}

// reverse
template <typename T>
MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(){return (c.rbegin());}

template <typename T>
MutantStack<T>::reverse_iterator	MutantStack<T>::rend(){return (c.rend());}

// const_reverse
template <typename T>
MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const {return (c.rbegin());}

template <typename T>
MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const {return (c.rend());}
