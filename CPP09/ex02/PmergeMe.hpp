#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <exception>

#define TEMPLATE template <typename T>

TEMPLATE
void	jacob_sthal(T& min, T& max){

}

TEMPLATE
void	make_pairs(T& list){
	int	odd_number = -1;
	if (list.size() % 2 != 0){
		odd_number = list.back();
		list.pop_back();
	}
	T min;
	T max;
	for (uint i = 0; i < list.size(); i+=2){
		if (list[i] > list[i + 1]){
			std::swap(list[i], list[i + 1]);
		}
		min.push_back(list[i]);
		max.push_back(list[i + 1]);
	}
	std::sort(max.begin(), max.end());
	jacob_sthal(min, max);
	std::cout << "MAX:\n";
	for(typename T::iterator it = max.begin(); it != max.end(); ++it){
		std::cout << *it << "\n";
	}
	static_cast<void>(odd_number);
}

#endif
