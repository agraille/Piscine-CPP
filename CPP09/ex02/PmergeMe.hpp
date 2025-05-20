#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <exception>
#include <utility>
#include <ctime>

#define TEMPLATE template <typename T>

std::vector<int> generateJacobsthalNumbers(int limit) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    int i = 2;
    while (true) {
        int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        if (next > limit)
            break;
        jacobsthal.push_back(next);
        ++i;
    }
    return jacobsthal;
}

std::vector<int> getJacobsthalInsertionOrder(int size) {
    std::vector<int> result;
    std::vector<int> jacobsthal = generateJacobsthalNumbers(size);
    std::vector<bool> used(size + 1, false);
    used[0] = true;

    for (size_t i = 1; i < jacobsthal.size() && jacobsthal[i] <= size; ++i) {
        if (!used[jacobsthal[i]]) {
            result.push_back(jacobsthal[i]);
            used[jacobsthal[i]] = true;
        }
    }

    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        int start = jacobsthal[i - 1];
        int end = jacobsthal[i];

        for (int j = end - 1; j > start; --j) {
            if (j <= size && !used[j]) {
                result.push_back(j);
                used[j] = true;
            }
        }
    }

    for (int i = 1; i <= size; ++i) {
        if (!used[i]) {
            result.push_back(i);
        }
    }

    return result;
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

    bool hasOdd = false;
    typename T::value_type oddElement;
    if (container.size() % 2 != 0) {
        hasOdd = true;
        oddElement = container.back();
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

    T mainChain;
    std::vector<typename T::value_type> minElements;

    mainChain.push_back(pairs[0].first);

    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].second);
        if (i > 0)
            minElements.push_back(pairs[i].first);
    }

    std::vector<int> insertionOrder = getJacobsthalInsertionOrder(minElements.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        int index = insertionOrder[i] - 1;
        if (index < static_cast<int>(minElements.size())) {
            typename T::value_type valueToInsert = minElements[index];
            typename T::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
            mainChain.insert(it, valueToInsert);
        }
    }

    if (hasOdd) {
        typename T::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(it, oddElement);
    }

    container = mainChain;
}

TEMPLATE
void make_pairs(T& list) {

    std::vector<int> vecList(list.begin(), list.end());
    clock_t vecStart = clock();
    std::cout << "Avant tri: ";
    for (size_t i = 0; i < vecList.size() && i < 10; ++i)
        std::cout << vecList[i] << " ";
    if (vecList.size() > 10)
        std::cout << "...";
    std::cout << std::endl;

    fordJohnsonSort(vecList);

    clock_t vecEnd = clock();
    double vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000;

    std::deque<int> dequeList(list.begin(), list.end());
    clock_t dequeStart = clock();
    fordJohnsonSort(dequeList);
    clock_t dequeEnd = clock();
    double dequeTime = static_cast<double>(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Après tri avec PmergeMe: ";
    for (size_t i = 0; i < vecList.size(); ++i)
        std::cout << vecList[i] << " ";
    std::cout << std::endl;

    std::cout << "Temps pour std::vector: " << vecTime << " us" << std::endl;
    std::cout << "Temps pour std::deque : " << dequeTime << " us" << std::endl;
}

#endif
