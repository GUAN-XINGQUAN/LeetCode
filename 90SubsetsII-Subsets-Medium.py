class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        nums.sort()
        prevAddStart = 0
        for idx in range(len(nums)):
            length = len(ans)
            startIdx = 0
            if idx > 0 and nums[idx - 1] == nums[idx]:
                startIdx = prevAddStart
            prevAddStart = len(ans)
            for _idx in range(startIdx, length):
                ans.append(list(ans[_idx]) + [nums[idx]])
        return ans
"""
https://leetcode.com/problems/subsets-ii/
Subsets. BFS. 
"""