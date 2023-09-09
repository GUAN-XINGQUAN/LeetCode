#include <unordered_set>
#include <iostream>

int main()
{
	// initialize a hash set
	std::unordered_set<int> numSet;
	std::unordered_set<int> numSetRef;

	// insert an element: O(1); this is to insert a copy of the original value
	// return an iterator and bool to denote if the value is successfully inserted
	std::pair<std::unordered_set<int>::iterator, bool> inserResult1 = numSet.insert(0);
	std::pair<std::unordered_set<int>::iterator, bool> inserResult2 = numSet.insert(1);

	// delete an element: O(1)
	numSet.erase(0);

	// find an element: O(1)
	std::unordered_set<int>::iterator it = numSet.find(1);

	// get the number of elements
	size_t size = numSet.size();

	// determine if the set is empty
	bool isEmpty = numSet.empty();

	// count the occurence of a certain element: O(1)
	size_t ct = numSet.count(1);

	// get the number of buckets: O(1)
	size_t numBucket = numSet.bucket_count();

	// get the maximum number of buckets that the hash table can have: O(1)
	size_t numMaxBucket = numSet.max_bucket_count();

	// get the number of elements in the bucket with index n: O(1)
	size_t numEleBucket = numSet.bucket_size(0);

	// get the load factor: O(1)
	double loadFactor = numSet.load_factor();

	// get the maximum load factor: O(1)
	double maxLoadFactor = numSet.max_load_factor();

	// remove all elements from the set: O(n)
	numSet.clear();

	// swap two sets: < O(n); should be O(1)
	numSet.swap(numSetRef);

	// constructs elements within the set; different from insert() which copies the value: O(1)
	// does not change the set if the element already exist
	std::pair<std::unordered_set<int>::iterator, bool> emplaceResult = numSet.emplace(100);
}