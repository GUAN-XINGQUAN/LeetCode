# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
"""
Use divide and conquer.

What is the minimum depth if we already get the left branch and right branch depth:
    We just get the min(leftBranchDepth, rightBranchDepth) + 1
However, the derivation above has an assumption: both left branch and right branch exist.
If not, we just need to focus on the side that exists.
"""

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 1
        elif root.left and root.right:
            return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
        elif root.left:
            return self.minDepth(root.left) + 1
        else:
            return self.minDepth(root.right) + 1
        
