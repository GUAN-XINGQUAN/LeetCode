# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self,root):
        if not root:
            return 0
        else:
            return max(self.helper(root.left), self.helper(root.right)) + 1
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        return self.helper(root)
"""
https://leetcode.com/problems/maximum-depth-of-binary-tree/
BFS/Recursion
"""