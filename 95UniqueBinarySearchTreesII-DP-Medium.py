# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        dp = [[[] for _ in range(n + 1)] for _ in range(n + 1)]
        for step in range(1, n + 1):
            for i in range(1, n - step + 2):
                j = i + step - 1
                for sepIdx in range(i, j + 1):
                    ans1 = [None, ]
                    ans2 = [None, ]
                    if sepIdx != i:
                        ans1 = dp[i][sepIdx - 1]
                    if sepIdx != j:
                        ans2 = dp[sepIdx + 1][j]
                    for ans_1 in ans1:
                        for ans_2 in ans2:
                            dp[i][j].append(TreeNode(sepIdx, ans_1, ans_2))
        return dp[1][n]
"""
https://leetcode.com/problems/unique-binary-search-trees-ii/
DP & Subsets
"""