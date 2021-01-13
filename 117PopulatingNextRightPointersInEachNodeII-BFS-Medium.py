"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
from collections import deque
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        q = deque()
        q.append(root)
        while q:
            lenq = len(q)
            for i in range(lenq):
                curNode = q.popleft()
                if i < lenq - 1:
                    curNode.next = q[0]
                if curNode.left:
                    q.append(curNode.left)
                if curNode.right:
                    q.append(curNode.right)
        return root
"""
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
BFS. BFS will organize all elements in the queue with the order "1,2,3,4,5,7"
""" 