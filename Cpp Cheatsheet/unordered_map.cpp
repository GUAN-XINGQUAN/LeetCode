#include<unordered_map>
#include<iostream>

int main()
{
	// declare an unordered map
	std::unordered_map<int, int> valIndex;

	// insert an element: O(1)
	std::pair<std::unordered_map<int, int>::iterator, bool> insertResult1 = valIndex.insert({0, 1});
	std::pair<std::unordered_map<int, int>::iterator, bool> insertResult2 = valIndex.insert(std::make_pair(0, 1));
	valIndex[0] = 1;

	// modify the element: O(1)
	valIndex[0] = 99;

	// find the element: O(1)
	std::unordered_map<int, int>::iterator it = valIndex.find(0);
	std::cout << "Find the element: " << it->first << " " << it->second << std::endl;

	// delete the element: O(1)
	valIndex.erase(it);
	valIndex.erase(100);

	// check if an element exists: O(1)
	size_t check = valIndex.count(0);

	// get the size: O(1)
	size_t size = valIndex.size();

	// remove all elements: O(n)
	valIndex.clear();

	// get the number of bucket: O(1)
	size_t numBucket = valIndex.bucket_count();

	// get the maximum number of bucket: O(1)
	size_t maxNumBucket = valIndex.max_bucket_count();

	// get the number of elements in the bucket with index 0: O(1)
	size_t numEleBucket = valIndex.bucket_size(0);

	// get the load factor: O(1)
	double loadFactor = valIndex.load_factor();

	// get the max load factor: O(1)
	double maxLoadFactor = valIndex.max_load_factor();
}