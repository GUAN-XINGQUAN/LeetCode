# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
Traverse the entire tree and track the node's value and associated frequency into a hash table. Then get the mode from this hash table.
In Python, we could use defaultdict(int) such that the uninitialized key has a value of zero.
"""

class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        val2Count = collections.defaultdict(int)
        self.getCount(root, val2Count)
        maxCount = max(val2Count.values())
        result = []
        for val, count in val2Count.items():
            if count == maxCount:
                result.append(val)
        return result

    def getCount(self, root, val2Count):
        if root is None:
            return
        val2Count[root.val] += 1
        self.getCount(root.left, val2Count)
        self.getCount(root.right, val2Count)