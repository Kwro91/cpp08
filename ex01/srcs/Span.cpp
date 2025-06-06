#include "../includes/Span.hpp"

const char	*Span::FullSpanException::what() const throw(){
	return ("Exception: The span is full.");
}

const char	*Span::NoSpanException::what() const throw(){
	return ("Exception: No span found.");
}

const char	*Span::InvalidSpanException::what() const throw(){
	return ("Exception: Invalid span.");
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
	_container.reserve(s._container.capacity());
	_container = s._container;
	return (*this);
}

int	Span::shortestSpan(){
	if (_container.size() <= 1)
		throw InvalidSpanException();
	int span = -1;
	std::vector<int>::iterator it = _container.begin();
	std::vector<int>::iterator itend = _container.end();
	itend--;
	for (; it != itend ; itend--)
	{
		for(; it != itend ; it++)
		{
			if (*it >= *itend)
			{
				int value = *it - *itend;
				if (value < span || span == -1)
					span = value;
			}
			else
			{
				int value = *itend - *it;
				if (value < span || span == -1)
					span = value;
			}
		}
		it = _container.begin();
	}
	return (span);
}

int	Span::longestSpan(){
	if (_container.size() <= 1)
		throw InvalidSpanException();
	std::vector<int> tmp(_container);
	std::sort(tmp.begin(), tmp.end());
	int max = tmp[tmp.size() - 1] - tmp[0];
	return (max);
}

void	Span::addNumber(int n){
	if (_container.size() == _container.capacity())
		throw FullSpanException();
	_container.push_back(n);
}

void	Span::addRange(std::vector<int>::iterator b, std::vector<int>::iterator e){
	size_t sizeNew = static_cast<unsigned long>(std::distance(b, e)); //std::distance return an int
	size_t size = (_container.capacity() - _container.size());
	if (size < sizeNew)
		throw FullSpanException();
	_container.insert(_container.end(), b, e);
}

void	Span::printVec(){
	std::vector<int> tmp(_container);
	std::sort(tmp.begin(), tmp.end());
	for(size_t i = 0 ; i < tmp.size() ; i++)
	{
		std::cout << tmp[i] << " ";
		if (i != 0 && i % 10 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}
