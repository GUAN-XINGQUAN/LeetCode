class Solution:
    def numTrees(self, n: int) -> int:
        # A maxes list is not needed here, since our number list is 1, 2, 3, 4, ... , n, which is well sorted.
        if n == 1:
            return 1
        dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
        for i in range(1, n + 1):
            dp[i][i] = 1
        for winSize in range(2, n + 1):
            for leftIdx in range(1, n + 1 - winSize + 1):
                rightIdx = leftIdx + winSize - 1
                for rootIdx in range(leftIdx, rightIdx + 1):
                    leftTreeNum = dp[leftIdx][rootIdx - 1] if rootIdx != leftIdx else 1
                    rightTreeNum = dp[rootIdx + 1][rightIdx] if rootIdx != rightIdx else 1
                    dp[leftIdx][rightIdx] += leftTreeNum * rightTreeNum
        return dp[leftIdx][rightIdx]
"""
https://leetcode.com/problems/unique-binary-search-trees/
DP Merge intervals problem. 
Since all BST can be traversed in an in-order manner,
we need to decide which node is root, and the possible combinations of its 2 children. 
"""