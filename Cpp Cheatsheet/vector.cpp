#include <vector>
#include <iostream>

int main()
{
	// initialize a vector: O(n)
	std::vector<int> myVec1(10, 0);  // 10 elements and each one is zero
	std::vector<int> myVec2{ 10, 10 };  // a vector {10, 10}
	std::vector<int> myVec3 = { 10, 10 };  // a vector {10, 10}

	// append an element at the end: amortized O(1)
	myVec1.push_back(11);

	// remove the last element: O(1)
	myVec2.pop_back();

	// insert an element at a specified location: O(n)
	myVec3.insert(myVec3.begin(), 1);

	// remove an element at a designated location: O(n)
	std::vector<int>::iterator it = myVec3.erase(myVec3.begin() + 1);  // point to the next element

	// get the size of the vector: O(1)
	size_t size = myVec1.size();

	// get the capacity of the vector: O(1)
	size_t capacity = myVec1.capacity();  // capacity is typically greater than the size

	// checks if the vector is empty: O(1)
	bool isEmpty = myVec1.empty();

	// remove all elements: O(n)
	myVec3.clear();

	// get the first and last elements: O(1)
	int first = myVec1.front();
	int last = myVec1.back();

	// get the element with an index: O(1)
	int ele1 = myVec1[3];

	// get the element with an index with bound checking: O(1)
	int ele2 = myVec1.at(3);  // will throw an exception if index is out of bound

	// allocate a vector such that it is enough for number of elements without resizing: O(n)
	std::vector<int> myReserve;
	myReserve.reserve(10);  // reserve the spots for 10 elements without the need for resizing

	// request the vector to reduce its capacity to fit the size
	myVec1.shrink_to_fit();

	// swap two vectors: O(1)
	myVec1.swap(myVec2);
}