class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        prevTar = None
        m = []
        for tarIdx in range(len(nums) - 2):
            tarVal = nums[tarIdx]
            if tarVal == prevTar:
                continue
            else:
                prevTar = tarVal
            
            prevLeft = None
            prevRight = None
            leftIdx = tarIdx + 1
            rightIdx = len(nums) - 1
            while leftIdx < rightIdx:
                leftVal = nums[leftIdx]
                rightVal = nums[rightIdx]
                
                if leftVal == prevLeft:
                    leftIdx += 1
                    continue
                if rightVal == prevRight:
                    rightIdx -= 1
                    continue
                    
                if leftVal + rightVal == 0 - tarVal:
                    ans.append([tarVal, leftVal, rightVal])
                    prevLeft = leftVal
                    prevRight = rightVal
                    leftIdx += 1 
                    rightIdx -= 1
                elif leftVal + rightVal > 0 - tarVal:
                    prevRight = rightVal
                    rightIdx -= 1
                else:
                    prevLeft = leftVal
                    leftIdx += 1
                    
        return ans
    
"""
https://leetcode.com/problems/3sum/
2Pointer problem. Sort first. 
"""