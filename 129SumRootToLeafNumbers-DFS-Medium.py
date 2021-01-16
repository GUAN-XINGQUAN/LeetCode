# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = 0
    def sumNumbers(self, root: TreeNode, prevAns=0, ifRoot=True) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            self.ans += prevAns * 10 + root.val
        self.sumNumbers(root.left, prevAns * 10 + root.val, False)
        self.sumNumbers(root.right, prevAns * 10 + root.val, False)
        return self.ans
"""
https://leetcode.com/problems/sum-root-to-leaf-numbers/
DFS. 
"""