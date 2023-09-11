#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

bool comparator(int& a, int& b)
{
	// expect true if 1st argument goes before 2nd argument in the sorted array
	// sort in descending order
	return a > b;
}

int main()
{
	// sort an array or a STL container
	// std::sort(iterator1, iterator2, customComparatorFunction);
	std::vector<int> vec1 = {5, 3, 9, 0 };
	std::sort(vec1.begin(), vec1.end(), std::less<int>());  // this is default option: from small to large
	std::sort(vec1.begin(), vec1.end(), std::greater<int>());  // from large to small
	std::sort(vec1.begin(), vec1.end(), std::less_equal<int>());  // from small to large <=
	std::sort(vec1.begin(), vec1.end(), std::greater_equal<int>());  // from large to small >=
	std::sort(vec1.begin(), vec1.end(), comparator);  // customized comparison function

	// reverse an ordered container
	std::reverse(vec1.begin(), vec1.end());

	// find if an element exists and return the iterator
	std::vector<int>::iterator it1 = std::find(vec1.begin(), vec1.end(), 3);

	// count how many times one element occurs
	int count = std::count(vec1.begin(), vec1.end(), 5);

	// get the cumulative sunmmation
	// this one comes from <numeric>
	int sum = std::accumulate(vec1.begin(), vec1.end(), 0);

	// check if an element exists using binary search: array must be sorted
	bool exists = std::binary_search(vec1.begin(), vec1.end(), 5);

	// get first element that >= target value: array must be sorted in ascending order 
	std::vector<int>::iterator it3 = std::lower_bound(vec1.begin(), vec1.end(), 2);

	// get first elemeng that > target value: array must be sorted in ascending order 
	std::vector<int>::iterator it4 = std::upper_bound(vec1.begin(), vec1.end(), 2);
}
