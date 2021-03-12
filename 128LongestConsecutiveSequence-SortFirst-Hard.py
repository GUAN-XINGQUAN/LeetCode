class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return len(nums)
        nums = list(set(nums))
        nums.sort()
        ans = 1
        curLen = 1
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1] - 1:
                curLen += 1
                ans = max(curLen, ans)
            else:
                curLen = 1
        return ans
"""
https://leetcode.com/problems/longest-consecutive-sequence/
Sort First.
"""