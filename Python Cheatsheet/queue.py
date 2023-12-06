# Python built-in double-ended queue
from collections import deque

# append element to the right end of deque
myQueue.append(1)

# append element to the left end of deque
myQueue.appendleft(0)

# remove and return the rightmost element
myQueue.pop()

# remove and return the leftmost element
myQueue.popleft()

# Implement queue from scratch
class MyQueue:
    def __init__(self):
        self.items = []
    
    def enqueue(self, item):
        self.items.append(item)
    
    def isEmpty(self):
        return len(self.items) == 0

    def dequeue(self):
        if not self.isEmpty():
            return self.items.pop(0)
        else:
            raise Exception('The queue has zero element and cannot perform dequeue operation.')
    
    def getSize(self):
        return len(self.items)

