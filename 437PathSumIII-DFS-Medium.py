# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ps = {0:1, }
    def _helper(self, root, curSum, sum):
        if root == None:
            return 0
        curSum += root.val
        ans = 0
        if curSum - sum in self.ps:
            ans = self.ps[curSum - sum]
        if curSum in self.ps:
            self.ps[curSum] += 1
        else:
            self.ps[curSum] = 1
        ans += self._helper(root.left, curSum, sum) + self._helper(root.right, curSum, sum)
        self.ps[curSum] -= 1
        return ans
        
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if root == None:
            return 0
        return self._helper(root, 0, sum)
"""
https://leetcode.com/problems/path-sum-iii/
DFS + prefix sum.
"""