# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
    Binary search tree: left child value <= parent val <= right child value
    Let's imagine the binary search tree as a special "array" and we have two markers pointing to two nodes in this "array":
    small marker points to the node whose value <= target
    large marker points to the node whose value >= target
    We keep moving small and large markers until we traverse to the leaf.
    Then the cloest value must be either small or large marker.

    How to move the markers?
    If current node <= target:
        the target value must be left branch
        the larger marker must be the root
    else:
        the target value must be right branch
        the small marker must be the root
    finally choose between two markers
"""

class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        curNode, lower, upper = root, root, root
        while curNode:
            if curNode.val >= target:
                lower = curNode
                curNode = curNode.left
            else:
                upper = curNode
                curNode = curNode.right
        # Python min() function customize:
        # key allows you to customize the comparison: tuple(var1, var2)
        # use var1 to return smaller one; if tie, then use var2
        return min([lower.val, upper.val], key=lambda x : (abs(x - target), x))