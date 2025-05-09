#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

// Colors /////////
#define WHITE "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define ROSE "\033[1;35m"
#define CYAN "\033[1;36m"

///////////////EXCEPTION///////////////////////////

template <typename T>
class NotInContainerException : public std::exception {
	public :
		const char	*what() const throw();
	};

	template <typename T>
const char	*NotInContainerException<T>::what() const throw(){
	return ("Error: could not find given value in the container.");
}

//////////////////FUNCTION/////////////////////////

template <typename T>
int	easyfind(T &container, int n){
	typename T::iterator it = std::find(container.begin(), container.end(), n); //marche avec tout les container sequentiel
	if (it == container.end())
		throw NotInContainerException<T>();
	std::cout << GREEN << "Value " << n << " found." << WHITE << std::endl;
	return (n);
}
#endif
