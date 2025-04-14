#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

// Colors /////////
#define WHITE "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define ROSE "\033[1;35m"
#define CYAN "\033[1;36m"

template <typename T>
class MutantStack : public std::stack<T> {
	private :

	public :
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &m);
		MutantStack	&operator=(const MutantStack &m);

		// iterators based on std::deque that is the default use for std::stack
		// container_type adapt the container used (usually deque, vector & list).
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		
		iterator				begin();
		iterator				end();

		const_iterator			begin() const;
		const_iterator			end() const;
		
		reverse_iterator		rbegin();
		reverse_iterator		rend();

		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

#include "MutantStack.tpp"

#endif