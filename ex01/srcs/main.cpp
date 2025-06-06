#include "../includes/Span.hpp"
#include <iostream>
#include <cstdlib> // pour rand() et srand()
#include <ctime>   // pour time()

void	testSubject(){
	std::cout << GREEN << "=== Test subject ===" << WHITE << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printVec();
	std::cout << "Short: " << sp.shortestSpan() << std::endl;
	std::cout << "Long: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void	testInvalidAdd(){
	std::cout << GREEN << "=== Test invalid add===" << WHITE << std::endl;
	Span sp = Span(5);
	for (int i = 0; i < 10; i++)
		sp.addNumber(i);
}

void	testInvalidShortest(){
	std::cout << GREEN << "=== Test invalid shortest===" << WHITE << std::endl;
	Span sp = Span(1);
	sp.addNumber(1);
	std::cout << "Short: " << sp.shortestSpan() << std::endl;
}

void	testInvalidLongest(){
	std::cout << GREEN << "=== Test invalid longest===" << WHITE << std::endl;
	Span sp = Span(1);
	sp.addNumber(1);
	std::cout << "Long: " << sp.longestSpan() << std::endl;
}

int	findVector(std::vector<int> &save, int value){
	std::vector<int>::iterator it = save.begin();
	std::vector<int>::iterator itend = save.end();
	for (; it != itend ; it++)
	{
		if (*it == value)
			return (1);
	}
	return (0);

}

void	testN(unsigned int n){
	if (n > 15000)
	{
		std::cout << "15000 max for n" << std::endl;
		return ;
	}
	std::cout << GREEN << "=== Test " << n << "random nb ===" << WHITE << std::endl;
	Span sp = Span(n);
	std::srand(std::time(0));
	std::vector<int> save;
	save.reserve(n);

	for (size_t i = 0 ; i < n ; i++)
	{
		int nb = std::rand() % (n * 2);
		while (findVector(save, nb) != 0) //pour les doublons
			nb = std::rand() % (n * 2);
		sp.addNumber(nb);
		save.push_back(nb);
	}
	sp.printVec();
	std::cout << "Short: " << sp.shortestSpan() << std::endl;
	std::cout << "Long: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void	testAddRange(){
	std::cout << GREEN << "=== Test valid add range nb ===" << WHITE << std::endl;
	std::vector<int> v;
	Span sp = Span(100);

	for (int i = 90 ; i < 100 ; i++) // 90->99
		v.push_back(i);
	for (int i = 0 ; i < 90 ; i++) // 0->89
		sp.addNumber(i);
	std::cout << "Before Range:" << std::endl;
	sp.printVec();
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator itend = v.end();
	std::cout << "After Range:" << std::endl;
	sp.addRange(it, itend);
	sp.printVec();
	std::cout << "Short: " << sp.shortestSpan() << std::endl;
	std::cout << "Long: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void	testBadAddRange(){
	std::cout << GREEN << "=== Test bad add range nb ===" << WHITE << std::endl;
	std::vector<int> v;
	Span sp = Span(100);

	for (int i = 90 ; i < 151 ; i++) // 90->150
		v.push_back(i);
	for (int i = 0 ; i < 90 ; i++) // 0->89
		sp.addNumber(i);
	std::cout << "Before Range:" << std::endl;
	sp.printVec();
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator itend = v.end();
	std::cout << "After Range:" << std::endl;
	sp.addRange(it, itend);
	sp.printVec();
	std::cout << "Short: " << sp.shortestSpan() << std::endl;
	std::cout << "Long: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void	testNegatif(){
		std::cout << GREEN << "=== Test MANUEL ===" << WHITE << std::endl;
	std::vector<int> v;
	Span sp = Span(20);

	for (int i = -10 ; i > -20 ; i--) // 90->150
		v.push_back(i);
	for (int i = 0 ; i > -10 ; i--) // 0->89
		sp.addNumber(i);
	std::cout << "Before Range:" << std::endl;
	sp.printVec();
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator itend = v.end();
	std::cout << "After Range:" << std::endl;
	sp.addRange(it, itend);
	sp.printVec();
	std::cout << "Short: " << sp.shortestSpan() << std::endl;
	std::cout << "Long: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

int main(){
	try {
		testSubject();
	} catch (std::exception &e){
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}

	try {
		testInvalidAdd();
	} catch (std::exception &e){
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}

	try {
		testInvalidShortest();
	} catch (std::exception &e){
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}

	try {
		testInvalidLongest();
	} catch (std::exception &e){
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}

	try {
		testN(10);
	} catch (std::exception &e){
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}

	try {
		testAddRange();
	} catch (std::exception &e){
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}
	
	try {
		testBadAddRange();
	} catch (std::exception &e){
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}

	try {
		testNegatif();
	} catch (std::exception &e){
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}
	return (0);
}