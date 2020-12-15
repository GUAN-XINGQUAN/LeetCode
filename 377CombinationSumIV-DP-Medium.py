class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        if not nums or target < nums[0]:
            return 0
        dp = [0] * (target + 1)
        dp[0] = 1
        for t in range(target + 1):
            for num in nums:
                if t - num >= 0:
                    dp[t] += dp[t - num]
        return dp[target]
"""
https://leetcode.com/problems/combination-sum-iv/
DP Unique path problem
Very interesting... a 1-D DP problem. 
"""