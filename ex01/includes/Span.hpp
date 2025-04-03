#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class Span {
	private :
		std::vector<int> _container;
		
		Span();

	public :
		Span(unsigned int size);
		~Span();
		Span(const Span &s);
		Span	&operator=(const Span &s);

		int		shortestSpan() const;
		int		longestSpan() const;
		void	printVec() const;
		void	addNumber(int n);

		class FullSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception {
			public :
				virtual const char	*what() const throw();
		};
};

#endif
