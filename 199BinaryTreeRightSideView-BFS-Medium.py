# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        ans = []
        if not root:
            return ans
        q = deque()
        q.append(root)
        while q:
            lenq = len(q)
            for i in range(lenq):
                curNode = q.popleft()
                if i == lenq - 1:
                    ans.append(curNode.val)
                if curNode.left:
                    q.append(curNode.left)
                if curNode.right:
                    q.append(curNode.right)
        return ans
"""
https://leetcode.com/problems/binary-tree-right-side-view/
BFS has a very interesting feature. It will traverse a graph strictly from left to right, and up to down. 
"""