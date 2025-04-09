#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

// Colors /////////
#define WHITE "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define ROSE "\033[1;35m"
#define CYAN "\033[1;36m"

class Span {
	private :
		std::vector<int> _container;
		
		Span();

	public :
		Span(unsigned int size);
		~Span();
		Span(const Span &s);
		Span	&operator=(const Span &s);

		int		shortestSpan();
		int		longestSpan();
		void	printVec();
		void	addNumber(int n);
		void	addRange(std::vector<int>::iterator b, std::vector<int>::iterator e);


		class FullSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception {
			public :
				virtual const char	*what() const throw();
		};

		class WrongSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
