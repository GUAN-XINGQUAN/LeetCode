class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        s = set()
        for i in nums:
            if i in s:
                return i
            else:
                s.add(i)
"""
https://leetcode.com/submissions/detail/436141112/
Cyclic Sort
"""