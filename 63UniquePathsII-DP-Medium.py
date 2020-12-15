class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        if obstacleGrid[0][0] == 1 or obstacleGrid[m - 1][n - 1] == 1:
            return 0
        dp[0][0] = 1
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    continue
                for (lastI, lastJ) in [(i - 1, j), (i, j - 1)]:
                    if 0 <= lastI <= m and 0 <= lastJ <= n and obstacleGrid[lastI][lastJ] == 0:
                        dp[i][j] += dp[lastI][lastJ]
        return dp[m - 1][n - 1]
"""
https://leetcode.com/problems/unique-paths-ii/
DP Unique path problem. 
"""