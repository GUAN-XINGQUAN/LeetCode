class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        for elem in nums:
            l = len(ans)
            for idx in range(l):
                ans.append(list(ans[idx]) + [elem])
        return ans
"""
https://leetcode.com/problems/subsets/
Subsets. 
"""