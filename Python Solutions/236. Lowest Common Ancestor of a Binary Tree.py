# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
Use divide and conquer:

Imagine we have a black box function that:
    if the node exist in the tree, return the node
    else: return null

Then we use this function on the left branch and right branch:
    Case 1: both left and right branches return valid nodes --> current root is LCA
    Case 2: if left branch returns valid node but not right --> left branch result is LCA
    Case 3: if right branch returns valid node but not left --> right branch result is LCA
    Case 4: none of them return valid nodes --> Not possible because problem statement forces both ndoes exist in the tree
"""

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.lca(root, p, q)
        
    def lca(self, root, p, q):
        if root is None or root == p or root == q:
            return root
        
        left = self.lca(root.left, p, q)
        right = self.lca(root.right, p, q)

        if left and right:
            return root
        elif left:
            return left
        elif right:
            return right
        else:
            return None  # not possible
        