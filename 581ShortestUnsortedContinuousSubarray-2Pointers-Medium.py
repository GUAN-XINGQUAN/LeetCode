class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        #-5,1,2,10,1,0,11
        leftValidIdx = None
        rightValidIdx = None
        if len(nums) == 0 or len(nums) == 1:
            return 0
        
        # Left to right
        curMin = None
        for wranglerIdx in range(len(nums)):
            wVar = nums[wranglerIdx]
            if wranglerIdx == 0:
                leftValidIdx = 0
                curMin = wVar
            else:
                if wVar < curMin: 
                    curMin = wVar
                    while leftValidIdx != None and nums[leftValidIdx] > curMin:
                        leftValidIdx -= 1
                        if leftValidIdx < 0:
                            leftValidIdx = None
                            break
                else:
                    if wranglerIdx - 1 == leftValidIdx:
                        leftValidIdx = wranglerIdx
                        curMin = wVar
                    else:
                        pass
        
        
        # Right to left
        curMax = None
        for wranglerIdx in range(len(nums) - 1, -1, -1):
            wVar = nums[wranglerIdx]
            if wranglerIdx == len(nums) - 1:
                rightValidIdx = wranglerIdx
                curMax = wVar
            else:
                if wVar > curMax:
                    curMax = wVar
                    
                    while rightValidIdx != None and nums[rightValidIdx] < wVar:
                        
                        
                        rightValidIdx += 1
                        if rightValidIdx > len(nums) - 1:
                            rightValidIdx = None
                else:
                    if wranglerIdx + 1 == rightValidIdx:
                        rightValidIdx = wranglerIdx
                        curMax = wVar
                    else:
                        pass
                        
        if leftValidIdx == len(nums) - 1:
            return 0
        
        startIdx = None
        endIdx = None
        if leftValidIdx == None:
            startIdx = 0
        else:
            startIdx = leftValidIdx + 1
        if rightValidIdx == None:
            endIdx = len(nums) - 1
        else:
            endIdx = rightValidIdx - 1
        # return leftValidIdx, rightValidIdx # For debugging
        return endIdx - startIdx + 1
        
    
"""
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
2 Pointer problem.
Apply 2 pointer to track valid substrings: left2right, and then right2left
"""