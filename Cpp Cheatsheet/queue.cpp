#include<queue>

int main()
{
	// declare a queue
	std::queue<int> myQueue;

	// add one element
	myQueue.push(10);
	myQueue.push(5);

	// access the front of the queue
	int front = myQueue.front();

	// access the back of the queue
	int back = myQueue.back();

	// pop out the front element (first in first out)
	myQueue.pop();

	// check if empty
	bool isEmpty = myQueue.empty();

	// get the size
	size_t size = myQueue.size();
}