class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        leftIdx = 0
        rightIdx = len(nums) - 1
        midVal, midIdx = None, None
        while leftIdx <= rightIdx:
            midIdx = (leftIdx + rightIdx) // 2
            midVal = nums[midIdx]
            if leftIdx == rightIdx:
                break
            if target == midVal:
                break
            if target < midVal:
                rightIdx = midIdx
            if target > midVal:
                leftIdx = midIdx + 1
                
        if target != midVal:
            return [-1, -1]
        
        leftIdx = midIdx
        rightIdx = midIdx
        
        foundLeft = False
        foundRight = False
        
        while foundLeft == False:
            if leftIdx == 0:
                foundLeft = True
            else:
                if nums[leftIdx - 1] == target:
                    leftIdx -= 1
                else:
                    foundLeft = True
                    
        while foundRight == False:
            if rightIdx == len(nums) - 1:
                foundRight = True
            else:
                if nums[rightIdx + 1] == target:
                    rightIdx += 1
                else:
                    foundRight = True
        
        return [leftIdx, rightIdx]

"""
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Binary Search
"""