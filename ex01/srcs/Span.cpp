#include "../includes/Span.hpp"

const char	*Span::FullSpanException::what() const throw(){
	return ("Exception: The span is full.");
}

const char	*Span::NoSpanException::what() const throw(){
	return ("Exception: No span found.");
}

//////////////

Span::Span(){}

///////////////

Span::~Span(){}

Span::Span(unsigned int size) {
	_container.reserve(size);
} 

Span::Span(const Span &s){
	*this = s;
}

Span	&Span::operator=(const Span &s){
	_container = s._container;
	return (*this);
}

int	Span::shortestSpan() const{
	return (0);
}

int	Span::longestSpan() const{
	return (0);
}

void	Span::addNumber(int n){
	if (_container.size() == _container.capacity())
		throw FullSpanException();
	_container.push_back(n);
}

void	Span::printVec() const{
	for(size_t i = 0 ; i < _container.size() ; i++)
	{
		std::cout << _container[i] << std::endl;
	}
}
