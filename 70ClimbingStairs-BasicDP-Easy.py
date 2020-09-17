class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2
        sol = [0, 1, 2]
        for _s in range(3, n + 1):
            sol.append(sol[_s - 1] + sol[_s - 2])
        return sol[n]
        
"""
https://leetcode.com/problems/climbing-stairs/submissions/

Applied DP here.
"""