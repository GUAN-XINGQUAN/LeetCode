class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        curSum = 0
        leftIdx = 0
        ans = len(nums)
        for rightIdx in range(len(nums)):
            rightVal = nums[rightIdx]
            leftVal = nums[leftIdx]
            curSum += rightVal
            while curSum - leftVal >= s and leftIdx < rightIdx:
                curSum -= leftVal
                leftIdx += 1
                leftVal = nums[leftIdx]
            if curSum >= s:
                ans = min(rightIdx - leftIdx + 1, ans)
        if ans == len(nums) and sum(nums) < s:
            return 0
        return ans
    
"""
https://leetcode.com/problems/minimum-size-subarray-sum/submissions/
A Sliding window problem.
Please pay attention to line14. Some ans at the beginning loops may be invalid.
"""