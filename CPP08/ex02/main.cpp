#include "MutantStack.hpp"

template <typename Container>
void	testContainer(Container& container) {
	container.push_back(5);
	container.push_back(17);
	std::cout << container.back() << std::endl;
	container.pop_back();
	std::cout << container.size() << std::endl;
	container.push_back(3);
	container.push_back(5);
	container.push_back(737);
	container.push_back(0);
	std::cout << "Stack size: " << container.size() << std::endl;

	typename Container::iterator it = container.begin();
	typename Container::iterator ite = container.end() - 1;
	++it;
	--it;
	while (ite != it)
	{
		std::cout << *ite << std::endl;
		--ite;
	}
}

int main() {
    std::cout << "Testing MutantStack" << "\n";
    MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	// std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Stack size: " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	--ite;
	while (ite != it)
	{
		std::cout << *ite << std::endl;
		--ite;
	}
	std::stack<int> s(mstack);

    std::cout << "\nTesting std::list" << "\n";
    std::vector<int> lstack;
    testContainer(lstack);

    return 0;
}
