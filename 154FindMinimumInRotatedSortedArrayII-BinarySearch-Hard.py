class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            print(left, right)
            leftVal = nums[left]
            rightVal = nums[right]
            if leftVal < rightVal:
                return nums[left]
            if left + 1 == right:
                return nums[right]
            if leftVal == rightVal:
                left += 1
                continue
            mid = (left + right) // 2
            midVal = nums[mid]
            
            # left-side is sorted (and leftVal > rightVal, always)
            if leftVal <= midVal:
                left = mid                    
                
            # right-side is sorted (and leftVal > rightVal, always)
            elif midVal <= rightVal:
                right = mid
        return nums[0]
"""
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Binary Search. We're continuing igonring the sorted part to find the cliff. 
If the cliff is not found, then there's no cliff. 
"""