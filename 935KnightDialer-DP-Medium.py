class Solution:
    def lastNum(self, x):
        if x == 1:
            return [6, 8]
        elif x == 2:
            return [7, 9]
        elif x == 3:
            return [4, 8]
        elif x == 4:
            return [0, 3, 9]
        elif x == 5:
            return []
        elif x == 6:
            return [0, 1, 7]
        elif x == 7:
            return [2, 6]
        elif x == 8:
            return [1, 3]
        elif x == 9:
            return [2, 4]
        elif x == 0:
            return [4, 6]
                
    def knightDialer(self, n: int) -> int:
        if n == 0:
            return 0
        m = 10 ** 9 + 7
        dp = [[0 for _ in range(10)] for _ in range(n)]
        dp[0] = [1] * 10  
        for r in range(1, n):
            for num in range(10):
                for lastN in self.lastNum(num):
                    dp[r][num] += dp[r - 1][lastN] % m
        return sum(dp[n - 1]) % m
"""
https://leetcode.com/problems/knight-dialer/solution/
DP Unique question problem
Fuck you python what kind of initiliazer do you want?!
"""