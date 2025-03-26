#include "../includes/easyfind.hpp"

int main(){
	try {
		std::vector<int> v;
		for (int i = 0 ; i < 51 ; i++)
			v.push_back(i);

		std::cout << BLUE << "Try with 42:" << WHITE << std::endl;
		int value = easyfind(v, 42);
		std::cout << "easyfind found: " << value << std::endl;

		std::cout << BLUE << "Try with 100:" << WHITE << std::endl;
		value = easyfind(v, 100);
		std::cout << "easyfind found: " << value << std::endl;

	} catch (std::exception &e) {
		std::cerr << YELLOW << e.what() << WHITE << std::endl;
	}
	return (0);
}
