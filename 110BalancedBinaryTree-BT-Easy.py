# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root):
        if not root:
            return 0, True
        leftH, ifLB = self.helper(root.left)
        rightH, ifRB = self.helper(root.right)
        leftH += 1
        rightH += 1
        if not ifLB or not ifRB:
            return -1, False
        elif abs(leftH - rightH) > 1:
            return -1, False
        else:
            return max(leftH, rightH), True
        
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        leftH, ifLB = self.helper(root.left)
        rightH, ifRB = self.helper(root.right)
        if not ifLB or not ifRB:
            return False
        elif abs(leftH - rightH) > 1:
            return False
        else:
            return True
"""
https://leetcode.com/problems/balanced-binary-tree/description/
Recursion. 
"""