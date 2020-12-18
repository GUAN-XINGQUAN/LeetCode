class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0 for _ in range(len(nums))]
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums)
        
        dp[0] = nums[0]
        dp[1] = nums[1]
        for i in range(2, len(nums)):
            dp[i] = nums[i] + dp[i - 2]
            if i >= 3:
                dp[i] = max(dp[i], nums[i] + dp[i - 3])
        return max(dp[-1], dp[-2])
"""
https://leetcode.com/problems/house-robber/
DP. dp[i] represents "if the i-th elem is selected, what's the current max val". 
"""