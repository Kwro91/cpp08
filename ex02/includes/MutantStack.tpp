#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &m){
	*this = m;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &m){
	this->c = m.c; //c is a protected container from std::stack
	return (*this);
}


// need the keyword typename to precise it's a type to the compiler
// iterator
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(){return (this->c.begin());}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(){return (this->c.end());}

// const
template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const {return (this->c.begin());}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const {return (this->c.end());}

// reverse
template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(){return (this->c.rbegin());}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(){return (this->c.rend());}

// const_reverse
template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const {return (this->c.rbegin());}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const {return (this->c.rend());}
