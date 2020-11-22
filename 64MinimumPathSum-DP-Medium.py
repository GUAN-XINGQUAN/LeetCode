class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        temp = [0 for _ in range(len(grid[0]))]
        dp = [list(temp) for _ in range(len(grid))]
        dp[0][0] = grid[0][0]
        for rowIdx in range(1, len(grid)):
            dp[rowIdx][0] = grid[rowIdx][0] + dp[rowIdx - 1][0]
        for colIdx in range(1, len(grid[0])):
            dp[0][colIdx] = grid[0][colIdx] + dp[0][colIdx - 1]
        for rowIdx in range(1, len(grid)):
            for colIdx in range(1, len(grid[0])):
                dp[rowIdx][colIdx] = min(dp[rowIdx - 1][colIdx], dp[rowIdx][colIdx - 1]) + grid[rowIdx][colIdx]
        return dp[len(grid) - 1][len(grid[0]) - 1]

"""
https://leetcode.com/problems/minimum-path-sum/
DP. dp[i][j] represents the min cost you spend to arrive grid[i][j].
Don't forget to add grid[i][j] after getting the min val!
"""