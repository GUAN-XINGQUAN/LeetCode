# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
Recall BST propery: left child val <= parent child val <= right child val

When adding a target node, we just move from root to the leaf by the following pattern:
    target val < current val --> move to left
    target val > current val --> move to right
after we move to leaf, append left with the new node.
"""

class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None:
            return TreeNode(val)
        curNode, parent = root, root
        while curNode:
            parent = curNode
            if val < curNode.val:
                curNode = curNode.left
            else:
                curNode = curNode.right
        # parent is the leaf now; curNode is None
        newNode = TreeNode(val)
        if parent.val < val:
            parent.right = newNode
        else:
            parent.left = newNode
        return root