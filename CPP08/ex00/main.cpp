#include "easyfind.hpp"
#include "easyfind.tpp"

int	main(){
	std::vector<int> tab1;
	tab1.push_back(1);
	tab1.push_back(2);
	tab1.push_back(3);
	tab1.push_back(4);
	tab1.push_back(5);

	std::deque<int> tab2;
	tab2.push_back(1);
	tab2.push_back(2);
	tab2.push_back(3);
	tab2.push_back(4);
	tab2.push_back(5);

	std::list<int> tab3;
	tab3.push_back(1);
	tab3.push_back(2);
	tab3.push_back(3);
	tab3.push_back(4);
	tab3.push_back(5);

	try {
        std::vector<int>::iterator it = easyfind(tab1, 5);
        std::cout << "Value found: " << *it << "\n";
    }
	catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
	}
	try {
        std::vector<int>::iterator it = easyfind(tab1, 42);
        std::cout << "Value found: " << *it << "\n";
    }
	catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
	}
	try {
        std::deque<int>::iterator it = easyfind(tab2, 1);
        std::cout << "Value found: " << *it << "\n";
    }
	catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
	}
	try {
        std::list<int>::iterator it = easyfind(tab3, 2);
        std::cout << "Value found: " << *it << "\n";
    }
	catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
	}
}
