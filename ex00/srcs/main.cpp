#include "../includes/easyfind.hpp"

int main(){
	std::vector<int> v; //fill with {0->50}
	for (int i = 0 ; i < 51 ; i++)
	v.push_back(i);
	
	std::vector<int> v2; //empty
	
	try {
		std::cout << BLUE << "Try with 42:" << WHITE << std::endl;
		easyfind(v, 42);
	} catch (std::exception &e) {
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}

	try {
		std::cout << BLUE << "Try with 100:" << WHITE << std::endl;
		easyfind(v, 100);
	} catch (std::exception &e) {
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}

	try {
		std::cout << BLUE << "Try with empty vector and 42:" << WHITE << std::endl;
		easyfind(v2, 42);
	} catch (std::exception &e) {
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}
	return (0);
}
