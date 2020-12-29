class Solution:
    def swap(self, arr, i, j):
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
        
    def missingNumber(self, nums: List[int]) -> int:
        i = 0
        maxium = len(nums)
        while i < len(nums):
            curElem = nums[i]
            if curElem < maxium and curElem != i:
                self.swap(nums, i, curElem)
                curElem = nums[i]
            else:
                i += 1
        for i in range(len(nums)):
            if nums[i] != i:
                return i
        return maxium
"""
https://leetcode.com/problems/missing-number/
Cyclic Sort.
The while loop confirms that all numbers in the arr are located in the index-corresponding position,
except for maxium.
Maxium may be wrongly located, or event not exist. 
"""