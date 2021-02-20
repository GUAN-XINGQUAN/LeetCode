class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        n = nums[0]
        for i in range(1, len(nums)):
            n ^= nums[i]
        return n
"""
https://leetcode.com/problems/single-number/
XOR. 
- m ^ m = 0.
- Taking XOR of a number with 0 returns the same number
- XOR is Associative & Commutative
"""