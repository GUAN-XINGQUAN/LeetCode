class Solution:
    def val2Idx(self, val, S):
        midPointIdx = S
        return midPointIdx + val
        
    def idx2Val(self, idx, S):
        midPointIdx = S
        return idx - midPointIdx    
    
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        target = S
        S = sum(nums)
        
        if len(nums) == 0 or (len(nums) == 1 and nums[0] != abs(target)) or (abs(target) > S):
            return 0        
        dp = [[0 for _ in range(S * 2 + 1)] for _ in range(len(nums))]
        dp[0][self.val2Idx(nums[0], S)] += 1
        dp[0][self.val2Idx(-1 * nums[0], S)] += 1
        for idx in range(1, len(nums)):
            val = nums[idx]
            for s in range(len(dp[idx])):
                sVal = self.idx2Val(s, S)
                for v in [val, -1 * val]:
                    idx0 = self.val2Idx(sVal - v, S)
                    if 0 <= idx0 <= S * 2:
                        dp[idx][s] += dp[idx - 1][idx0]                    
        return dp[len(nums) - 1][self.val2Idx(target, S)] 
"""
https://leetcode.com/problems/target-sum/
DP unique path problem. 
This is a very good problem. 
- Need to consider negative S.
- Range of second axis is [-sum, +sum], not [-target, target]
- You must select + or -. You cannot discard a number. 
- When nums[0] == 0: dp[0][midpoint] = 2 (line 17 & 18)
"""