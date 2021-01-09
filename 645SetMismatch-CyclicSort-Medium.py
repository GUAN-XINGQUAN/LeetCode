class Solution:
    def swap(self, arr, i, j):
        tmp = arr[i]
        arr[i] = arr[j]
        arr[j] = tmp
        
    def findErrorNums(self, nums: List[int]) -> List[int]:
        i = 0
        while i < len(nums):
            val = nums[i]
            if val != i + 1 and val != nums[val - 1]:
                self.swap(nums, i, val - 1)
            else:
                i += 1
        for i in range(len(nums)):
            if i + 1 != nums[i]:
                return [nums[i], i + 1]
"""
https://leetcode.com/problems/set-mismatch/
Cyclic Sort. 
"""