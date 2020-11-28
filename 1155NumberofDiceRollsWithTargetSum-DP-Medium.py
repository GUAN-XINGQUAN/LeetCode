class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        if target < d:
            return 0
        if target == d:
            return 1
        if target > d * f:
            return 0
        if d == 1:
            return 1

        
        tmp = [0 for _ in range(target + 1)]
        dp = [list(tmp) for _ in range(d + 1)]
        for t in range(1, target + 1):
            dp[1][t] = 1 if t <= f else 0
        for die in range(2, d + 1):
            for t in range(die, target + 1):
                for lastT in range(max(t - f, 1), min(t, (die - 1) * f + 1)):
                    dp[die][t] += dp[die - 1][lastT]
        return dp[d][target] % (7 + 10 ** 9)
    
"""
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
DP. Unique Path Problem.
The most tricky point for this problem, or, the differnce between this one and the "choose or not" DP problem, is you cannot drop each die. The min value the die can contribute is 1.
As a result, pay attention to line 19 and line 20. 
"""