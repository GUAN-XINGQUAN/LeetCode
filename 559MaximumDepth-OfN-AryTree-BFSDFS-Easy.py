"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        if not root.children:
            return 1
        ans = 0
        callStack = [(root, 1)]
        while callStack:
            curNode, curDepth = callStack.pop()
            ans = max(curDepth, ans)
            for c in curNode.children:
                callStack.append((c, curDepth + 1))
        return ans
"""
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
BFS/DFS
"""