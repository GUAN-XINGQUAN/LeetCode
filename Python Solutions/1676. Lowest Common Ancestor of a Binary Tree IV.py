# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
    Use divide and conquer
    Let's design a recursive function as follows:
    (1) if current node is inside [nodes], return current node
    (2) recursively calling this function on left branch and right branch separately
    (3) if left branch and right branch return the valid node, then current parent is outcome. Otherwise, the side that has the valid node is should be returned.
"""

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
        nodeSet = set(nodes)
        return self.helper(root, nodeSet)

    def helper(self, root: TreeNode, nodeSet: set[TreeNode]) -> TreeNode:
        if root is None or root in nodeSet:
            return root
        
        left = self.helper(root.left, nodeSet)
        right = self.helper(root.right, nodeSet)

        if left and right:
            return root
        elif left:
            return left
        elif right:
            return right
        else:
            return None