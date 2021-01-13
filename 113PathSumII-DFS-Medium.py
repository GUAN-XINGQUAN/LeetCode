# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = []
    def pathSum(self, root: TreeNode, sum: int, ans=[]) -> List[List[int]]:
        if not root:
            return self.ans
        if root.left == None and root.right == None and root.val == sum:
            self.ans.append(ans + [root.val])
        self.pathSum(root.left, sum - root.val, ans + [root.val])
        self.pathSum(root.right, sum - root.val, ans + [root.val])
        return self.ans
"""
https://leetcode.com/problems/path-sum-ii/
DFS. 
"""