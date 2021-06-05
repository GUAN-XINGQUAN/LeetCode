class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left2right = [0 for _ in range(len(nums))]
        right2left = [0 for _ in range(len(nums))]
        lastLeft = 1
        lastRight = 1
        for i in range(len(nums)):
            li = i
            ri = len(nums) - 1 - i
            
            left2right[li] = lastLeft * nums[li]
            lastLeft = left2right[li]
            
            right2left[ri] = lastRight * nums[ri]
            lastRight = right2left[ri]
        ans = [0 for _ in range(len(nums))]
        for i in range(1, len(nums) - 1):
            left = left2right[i - 1]
            right = right2left[i + 1]
            ans[i] = left * right
        ans[0] = right2left[1]
        ans[-1] = left2right[-2]
        return ans
"""
https://leetcode.com/problems/product-of-array-except-self/
Array.
"""