# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
Use divide and conquer
    Imagine we have a black box function that already organizes the left branch as a linked list and returns the last node of the left branch.
    When we use this function on the current node, we just need to：
    (1) link the left branch last node to current node's right child
    (2) link the curret node's right branch to left branch 1st node
    (2) set current node's left branch to None
    Recursively doing (1) to (3) for each node in the tree
"""

class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.helper(root)
        
    def helper(self, root:TreeNode) -> TreeNode:
        if root is None or (root.left is None and root.right is None):
            return root

        leftLastNode = self.helper(root.left)
        rightLastNode = self.helper(root.right)

        if leftLastNode:
            leftLastNode.right = root.right
            root.right = root.left
            root.left = None

        return rightLastNode if rightLastNode else leftLastNode
