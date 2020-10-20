class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # 0. Corner cases - elems not enough
        ans = []
        if len(nums) < 3:
            return ans
        
        # 1. Sort
        nums.sort()
        prevCur = None
        
        # 2. Start from left to rignt - 2
        for curI in range(len(nums) - 2):
            curVal = nums[curI]
            # 2.0 If curVal > 0, break
            if curVal > 0:
                break            
            
            # 2.1 Corner cases: dup with previous elem, 
            if curVal == prevCur:
                continue
            else:
                prevCur = curVal
                
            # 2.2 start from current + 1, right. Add together and compare with current. Avoid dup. 
            target = 0 - curVal
            lIdx = curI + 1
            rIdx = len(nums) - 1
            while lIdx < rIdx:
                l = nums[lIdx]
                r = nums[rIdx]
                if l + r > target:
                    rIdx -= 1
                elif l + r < target:
                    lIdx += 1
                elif l + r == target:
                    if not ans or not (curVal == ans[-1][0] and l in ans[-1] and r in ans[-1]):
                        ans.append([curVal, l, r])
                    lIdx += 1
                    rIdx -= 1
        return ans