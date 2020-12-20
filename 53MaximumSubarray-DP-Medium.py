class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [0 for _ in range(len(nums))]
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            val = nums[i]
            dp[i] = max(val, val + dp[i - 1])
        return max(dp)
"""
https://leetcode.com/problems/maximum-subarray/
DP. dp[i] stands for the largest array sum when num[i] is included. 
"""