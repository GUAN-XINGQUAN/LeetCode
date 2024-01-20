# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
This is a binary search tree, so the left.val <= root.val <= right.val

We can use this property to find the LCA:
    Ensure p is always the smaller node between [p, q]
    Case 1: p.val <= root.val <= q.val --> root is the LCA
    Case 2: p.val <= q.val <= root.val --> LCA must sit in the left branch
    Case 3: root.val <= p.val <= q.val --> LCA must sit in the right branch
"""

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # ensure p is the node with smaller value compared with q
        if p.val > q.val:
            return self.lowestCommonAncestor(root, q, p)

        if p.val <= root.val <= q.val:
            return root
        elif p.val <= q.val <= root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return self.lowestCommonAncestor(root.right, p, q)