class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        leftIdx = None
        for rightIdx in range(len(nums)):
            rightVal = nums[rightIdx]
            leftVal = None
            if leftIdx is not None:
                leftVal = nums[leftIdx]
            if rightVal == leftVal:
                pass
            else:
                if leftIdx is not None:
                    leftIdx += 1
                else:
                    leftIdx = 0
                if leftIdx == rightIdx:
                    pass
                else:
                    nums[leftIdx] = rightVal
        if leftIdx == None:
            return 0
        else:
            return leftIdx + 1
        
"""
https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/
2 Pointers problem. 
"""