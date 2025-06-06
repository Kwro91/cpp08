#include "../includes/MutantStack.hpp"

void	subject(){
	std::cout << GREEN << "=== Test subject ===" << WHITE << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	subjectList(){
	std::cout << GREEN << "=== Test subject with list ===" << WHITE << std::endl;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

void	testPerso(){
	std::cout << GREEN << "=== Test subject with list ===" << WHITE << std::endl;
	MutantStack<int> mstack;
	for (int i = 0; i < 100 ; i++)
		mstack.push(i);
	
	std::cout << YELLOW << "Test sur iterator basiques:" << WHITE << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	for (int count = 0; it != ite; it++){
		count++;
		std::cout << *it << " ";
		if (count % 5 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << YELLOW << "Test sur const_iterator:" << WHITE << std::endl;
	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	for (int count = 0; cit != cite; cit++){
		count++;
		std::cout << *cit << " ";
		if (count % 5 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Test sur reverse iterator:" << WHITE << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	for (int count = 0; rit != rite; rit++)
	{
		count++;
		std::cout << *rit << " ";
		if (count % 5 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Test sur const_reverse_iterator:" << WHITE << std::endl;
	MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	for (int count = 0; crit != crite; crit++)
	{
		count++;
		std::cout << *crit << " ";
		if (count % 5 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Test fct pop() x 50:" << WHITE << std::endl; //prove inheritance
	for (int i = 0; i < 50; i++)
		mstack.pop();
	it = mstack.begin();
	ite = mstack.end();
	for (int count = 0; it != ite; it++)
	{
		count++;
		std::cout << *it << " ";
		if (count % 5 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "Test modif iterator et const_iterator:" << WHITE << std::endl; //prove const read only
	cit = mstack.begin();
	it = mstack.begin();
	std::cout << "Iterator: mstack[0] = " << *it << std::endl;
	std::cout << "Const_Iterator: mstack[0] = " << *cit << std::endl;
	*it = 42;
	std::cout << "Iterator: mstack[0] = " << *it << std::endl;
	// *cit = -42; //can't compile with this line
	std::cout << "Const_Iterator: mstack[0] = " << *cit << std::endl;
	std::cout << "You must try to compile after removing the comment just above to test." << std::endl;
}

int main(){
	subject();
	subjectList();
	std::cout << std::endl << "///////////////////////////////////////////////////////////////" << std::endl << std::endl;
	testPerso();
}