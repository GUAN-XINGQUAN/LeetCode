class Solution:
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        dp0 = [[0 for _ in range(N)] for _ in range(N)]
        dp0[r][c] = 1.0
        s = 1
        for _ in range(K):
            s = 0
            dp1 = [[0 for _ in range(N)] for _ in range(N)]
            for i in range(N):
                for j in range(N):
                    for direction in [(1, 2), (2, 1), (1,-2), (-2, 1), (-1, -2), (-2, -1), (-1, 2), (2, -1)]:
                        lr, ud = direction
                        rowIdx = i + lr
                        colIdx = j + ud
                        if 0 <= rowIdx < N and 0 <= colIdx < N:
                            dp1[i][j] += dp0[rowIdx][colIdx] / 8 
                    s += dp1[i][j]
            dp0 = dp1
        return s
        
"""
https://leetcode.com/problems/knight-probability-in-chessboard/solution/
This is a very interesting DP problem.
The DP solution tries to combine duplicated operations into 1 operation. 
Fuck you python deep copy list. 
"""