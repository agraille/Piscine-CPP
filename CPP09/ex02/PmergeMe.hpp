#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <exception>
#include <sys/time.h>

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
std::vector<std::pair<T, T> > mergeSortPairs(std::vector<std::pair<T, T> >& pairs) {
    if (pairs.size() <= 1)
        return pairs;

    size_t mid = pairs.size() / 2;
    std::vector<std::pair<T, T> > left(pairs.begin(), pairs.begin() + mid);
    std::vector<std::pair<T, T> > right(pairs.begin() + mid, pairs.end());

    left = mergeSortPairs<T>(left);
    right = mergeSortPairs<T>(right);

    std::vector<std::pair<T, T> > result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i].second < right[j].second)
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }

    while (i < left.size())
        result.push_back(left[i++]);
    while (j < right.size())
        result.push_back(right[j++]);

    return result;
}

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

	pairs = mergeSortPairs<typename T::value_type>(pairs);

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
