#include "PmergeMe.hpp"

std::deque<std::pair<int, int> > mergeSortPairs(std::deque<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1)
        return pairs;

    size_t mid = pairs.size() / 2;
    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    left = mergeSortPairs(left);
    right = mergeSortPairs(right);

    std::deque<std::pair<int, int> > result;
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

void fordJohnsonSort(std::deque<int>& container) {
    if (container.size() <= 1)
        return;

    int	oddNumber = -1;
    if (container.size() % 2 != 0) {
        oddNumber = container.back();
        container.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size(); i += 2) {
        int a = container[i];
        int b = container[i + 1];
        if (a <= b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

	pairs = mergeSortPairs(pairs);

	std::deque<int>	maxlist;
    std::deque<int>	minlist;

    maxlist.push_back(pairs[0].first);

    for (size_t i = 0; i < pairs.size(); ++i) {
        maxlist.push_back(pairs[i].second);
        if (i > 0)
            minlist.push_back(pairs[i].first);
    }

    std::deque<int>	 insertionOrder = generateJacobsthalSuite(minlist.size(), maxlist);

    for (size_t i = 1; i < insertionOrder.size(); ++i) {
        int index = insertionOrder[i];
        if (index < static_cast<int>(minlist.size())) {
            int valueToInsert = minlist[index];
            std::deque<int>::iterator it = std::lower_bound(maxlist.begin(), maxlist.end(), valueToInsert);
            maxlist.insert(it, valueToInsert);
        }
    }
    if (oddNumber != -1) {
        std::deque<int>::iterator it = std::lower_bound(maxlist.begin(), maxlist.end(), oddNumber);
        maxlist.insert(it, oddNumber);
    }
    container = maxlist;
}

void run_deque(std::deque<int>& list) {
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
