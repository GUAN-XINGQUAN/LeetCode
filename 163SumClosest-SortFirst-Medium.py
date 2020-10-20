class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        # 1. init
        ans = None
        minAbsVal = None
        prevVal = None
        
        # 2. Sort 
        nums.sort()
        
        # 3. from 0 - len - 2 for curVal
        for curIdx in range(len(nums) - 2):
            curVal = nums[curIdx]
            if curVal == prevVal:
                continue
            else:
                prevVal = curVal
                
        
        # 4, while loop: left = curIdx + 1, right = len - 1
            lIdx = curIdx + 1
            rIdx = len(nums) - 1
            while lIdx < rIdx:
                lVal = nums[lIdx]
                rVal = nums[rIdx]
                val = target - curVal - lVal - rVal
                absVal = abs(val)
                if minAbsVal is None or absVal < minAbsVal:
                    ans = curVal + lVal + rVal
                    minAbsVal = absVal
                    if ans == target:
                        break;
                if val < 0:
                    rIdx -= 1
                if val > 0:
                    lIdx += 1
                    
            if ans == target:
                break
        return ans

"""
https://leetcode.com/problems/3sum-closest/submissions/
Same idea with 3 sum
"""
