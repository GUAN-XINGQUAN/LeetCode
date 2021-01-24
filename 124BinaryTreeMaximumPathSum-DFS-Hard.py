# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.maxVal = -1001
    def _helper(self, root):
        if root == None:
            return 0
        leftMax = max(self._helper(root.left),0)
        rightMax = max(self._helper(root.right),0)
        self.maxVal = max(self.maxVal, root.val + leftMax + rightMax, root.val + leftMax, root.val + rightMax)
        return max(leftMax, rightMax) + root.val
    
    def maxPathSum(self, root: TreeNode) -> int:
        if root == None:
            return 0
        leftMax = max(self._helper(root.left),0)
        rightMax = max(self._helper(root.right),0)
        return max(root.val + leftMax + rightMax, self.maxVal, root.val + leftMax, root.val + rightMax)
"""
https://leetcode.com/problems/binary-tree-maximum-path-sum/
DFS
"""