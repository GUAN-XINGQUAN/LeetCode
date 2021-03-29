class Node:
    def __init__(self, key, val, nextNode=None, prevNode=None):
        self.next = nextNode
        self.prev = prevNode
        self.val = val
        self.key = key

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.head = Node(-1, -1)
        self.tail = Node(-2, -2)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.lookup = dict()

    def get(self, key: int) -> int:
        if key not in self.lookup:
            return -1
        else:
            curNode = self.lookup[key]
            curNodePrev = curNode.prev
            curNodeNext = curNode.next
            curNodePrev.next = curNodeNext
            curNodeNext.prev = curNodePrev
            
            curNode.next = self.head.next
            self.head.next.prev = curNode
            curNode.prev = self.head
            self.head.next = curNode
            return self.lookup[key].val            

    def put(self, key: int, value: int) -> None:
        newNode = Node(key, value)
        if key in self.lookup:
            newNode = self.lookup[key]
            newNode.val = value
            newNode.prev.next = newNode.next
            newNode.next.prev = newNode.prev
        self.head.next.prev = newNode
        newNode.next = self.head.next
        newNode.prev = self.head
        self.head.next = newNode  
        self.lookup[key] = newNode
        
        if len(self.lookup) > self.cap:
            lastNode = self.tail.prev
            lastNode.prev.next = self.tail
            self.tail.prev = lastNode.prev
            del self.lookup[lastNode.key]             


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

"""
https://leetcode.com/problems/lru-cache/submissions/
This is a classic data structure problem.
We're using 2 data-structures to store infos.
1. dictionary for O(1) lookup & add & delete
2. double-linked list for O(1) order management, insertion, and deletion. 
"""