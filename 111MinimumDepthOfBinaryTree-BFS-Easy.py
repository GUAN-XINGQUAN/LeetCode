# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        q = deque()
        cnt = 0
        q.append(root)
        while q:
            cnt += 1
            for _ in range(len(q)):
                curNode = q.popleft()
                if curNode.left == None and curNode.right == None:
                    return cnt
                if curNode.left:
                    q.append(curNode.left)
                if curNode.right:
                    q.append(curNode.right)
"""
https://leetcode.com/problems/minimum-depth-of-binary-tree/
BFS.
"""