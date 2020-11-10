class Solution:
    def swap(self, nums, i, j):
        x = nums[i]
        nums[i] = nums[j]
        nums[j] = x
        
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        leftIdx = 0
        rightIdx = len(nums) - 1
        midIdx = 0
        while midIdx <= rightIdx:
            midVal = nums[midIdx]
            if midVal == 0:
                self.swap(nums, leftIdx, midIdx)
                leftIdx += 1
                midIdx += 1
                
            elif midVal == 1:
                midIdx += 1
                
            elif midVal == 2:
                self.swap(nums, midIdx, rightIdx)
                rightIdx -= 1
                # midIdx += 1
                
        return nums

"""
https://leetcode.com/problems/sort-colors/
2Pointers Problem
Pay attention to line 27. The reason is, between leftIdx and midIdx - 1, there're only 1s. However, this is not true for midIdx and rightIdx. 
Also be careful about the ">=" at line 14
"""