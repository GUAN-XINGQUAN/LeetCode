# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
    Use divide and conquer.
    Let's define a recursion function that returns the root of the deleted tree.
    The base case should be the "current node is the one to be deleted".
    Case 1：current node is leaf 
                --> just re-assign current node to None and return None
    Case 2: current node's one child is None and the other is not 
                --> return the non-None child
    Case 3: current node both children are not None:
                --> find the rightmost child and assign its value to current node
                --> delete rightmost child (using current function itself)

    The derivation case:
        if delete value < current node --> go left. else go right
"""

class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        # edge case
        if root is None:
            return None
        # base case
        if root.val == key:
            if root.left and root.right:
                temp = root.right
                while temp.left:
                    temp = temp.left
                root.val = temp.val
                root.right = self.deleteNode(root.right, temp.val)
            elif root.left:
                return root.left
            elif root.right:
                return root.right
            else:
                return None
        # derivation case
        elif root.val > key:
            root.left = self.deleteNode(root.left, key)
        else:
            root.right = self.deleteNode(root.right, key)
        
        return root