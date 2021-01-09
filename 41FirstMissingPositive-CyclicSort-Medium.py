class Solution:
    def swap(self, arr, i, j):
        tmp = arr[i]
        arr[i] = arr[j]
        arr[j] = tmp
        
    def firstMissingPositive(self, nums: List[int]) -> int:
        if len(nums) == 0 or (len(nums) == 1 and nums[0] != 1):
            return 1
        
        i = 0
        while i < len(nums):
            val = nums[i]
            if val > 0 and val < len(nums) and val - 1 != i and val != nums[val - 1]:
                self.swap(nums, i, val - 1)
            else:
                i += 1
        for i in range(len(nums)):
            if i + 1 != nums[i]:
                return i + 1
        return len(nums) + 1 # input = [1]
"""
https://leetcode.com/problems/first-missing-positive/
Cyclic Sort. 
If a "positive, and in index range" number exist, 
it will always be swapped to the "correct" position.
If a number is non-positive or duplicated, it will be left at the "wrong" position,
no matter how many they are. 
"""