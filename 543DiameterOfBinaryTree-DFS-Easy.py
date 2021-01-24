# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.maxVal = 0
    def _helper(self,root):
        if root == None:
            return -1
        leftVal = self._helper(root.left) + 1
        rightVal = self._helper(root.right) + 1
        self.maxVal = max(self.maxVal, leftVal + rightVal)        
        return max(leftVal, rightVal)  
    
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if root == None:
            return 0
        leftMax = self._helper(root.left) + 1
        rightMax = self._helper(root.right) + 1
        return max(self.maxVal, leftMax + rightMax)
"""
https://leetcode.com/problems/diameter-of-binary-tree/
DFS
"""