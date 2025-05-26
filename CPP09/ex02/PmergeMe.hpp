#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <exception>
#include <sys/time.h>
#include <array> 

#define TEMPLATE template <typename T>

TEMPLATE
T generateJacobsthalSuite(int limit, T& container) {
    T jacobsthal;
    static_cast<void>(container);
	int prev2 = 0;
    int prev1 = 1;
    int next = 0;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (true) {
        next = prev1 + 2 * prev2;
        if (next > limit)
            break;
        jacobsthal.push_back(next);
        prev2 = prev1;
        prev1 = next;
    }

    for (int i = 1; i <= limit; ++i) {
        bool found = false;
        for (typename T::iterator it = jacobsthal.begin(); it != jacobsthal.end(); ++it) {
            if (*it == i) {
                found = true;
                break;
            }
        }
        if (!found)
            jacobsthal.push_back(i);
    }
    return jacobsthal;
}

TEMPLATE
struct ComparePairSecond {
    bool operator()(const std::pair<T, T>& a, const std::pair<T, T>& b) const {
        return a.second < b.second;
    }
};

TEMPLATE
void fordJohnsonSort(T& container) {
    if (container.size() <= 1)
        return;

    int	oddNumber = -1;
    if (container.size() % 2 != 0) {
        oddNumber = container.back();
        container.pop_back();
    }

    std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;
    for (size_t i = 0; i < container.size(); i += 2) {
        typename T::value_type a = container[i];
        typename T::value_type b = container[i + 1];
        if (a <= b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    std::sort(pairs.begin(), pairs.end(), ComparePairSecond<typename T::value_type>());

    T maxlist;
    T minlist;

    maxlist.push_back(pairs[0].first);

    for (size_t i = 0; i < pairs.size(); ++i) {
        maxlist.push_back(pairs[i].second);
        if (i > 0)
            minlist.push_back(pairs[i].first);
    }

    T insertionOrder = generateJacobsthalSuite(minlist.size(), maxlist);

    for (size_t i = 1; i < insertionOrder.size(); ++i) {
        int index = insertionOrder[i];
        if (index < static_cast<int>(minlist.size())) {
            typename T::value_type valueToInsert = minlist[index];
            typename T::iterator it = std::lower_bound(maxlist.begin(), maxlist.end(), valueToInsert);
            maxlist.insert(it, valueToInsert);
        }
    }
    if (oddNumber != -1) {
        typename T::iterator it = std::lower_bound(maxlist.begin(), maxlist.end(), oddNumber);
        maxlist.insert(it, oddNumber);
    }
    container = maxlist;
}

TEMPLATE
void make_pairs(T& list) {
	timeval start, end;

    std::cout << "Before sort: \n";
    for (size_t i = 0; i < list.size(); ++i)
        std::cout << list[i] << " ";
    std::cout << "\n" << std::endl;

    gettimeofday(&start, NULL);
    fordJohnsonSort(list);
	gettimeofday(&end, NULL);

    std::cout << "Après tri avec PmergeMe: \n";
    for (size_t i = 0; i < list.size(); ++i)
        std::cout << list[i] << " ";
    std::cout << std::endl;

	long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds * 1000.0 + microseconds / 1000.0;
	std::cout << "Time for sort : " << elapsed << " ms" << std::endl;
}

#endif
