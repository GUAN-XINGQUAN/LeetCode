class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0 for _ in range(len(cost))]
        dp[0] = cost[0]
        dp[1] = cost[1]
        for idx in range(2, len(cost)):
            dp[idx] = min(dp[idx - 1], dp[idx - 2]) + cost[idx]
        return min(dp[len(cost) - 1], dp[len(cost) - 2])

"""
https://leetcode.com/problems/min-cost-climbing-stairs/
DP problem. dp[idx] represents, if select current stair, what's the min cost. 
"""