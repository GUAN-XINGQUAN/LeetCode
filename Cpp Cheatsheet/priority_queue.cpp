#include <queue>

bool compare(int& a, int& b)
{
	return a < b;
}

struct comparator {
	bool operator()(int& a, int& b)
	{
		return a < b;
	}
};

int main()
{
	// initialize a priority queue: max heap: large value pops out first
	std::priority_queue<int> max_heap;  // default
	std::priority_queue<int, std::vector<int>, std::less<int>> max_heap2;

	// initialize a priority queue: min heap: smaller value pops out first
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

	// add elements
	max_heap.push(10);
	max_heap.push(20);
	max_heap.push(30);

	// get the top element
	// remember that priority_queue does not support accessing the non-top element
	int top = max_heap.top();

	// remove the top element
	max_heap.pop();

	// get the size
	size_t s = max_heap.size();

	// check if empty
	bool isEmpty = max_heap.empty();
	
	// customize the priority queue comparator
	std::priority_queue<int, std::vector<int>, decltype(&compare)> myQueue1;
	std::priority_queue<int, std::vector<int>, comparator> myQueue2;
}