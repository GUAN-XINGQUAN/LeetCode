class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = nums[0]
        for i in range(1, len(nums)):
            xor = xor ^ nums[i]
        
        rightMostDiff = 1
        while xor & rightMostDiff == 0:
            rightMostDiff *= 2
        
        num1 = 0
        num2 = 0
        for num in nums:
            if num & rightMostDiff == 0:
                num1 = num1 ^ num
            else:
                num2 = num2 ^num
        return [num1, num2]
"""
https://leetcode.com/problems/single-number-iii/
XOR.
Since num1 != num2,
num1 ^ num2 != 0. There must be at least 1 bit difference (xor[i] = 1)
Use this feature to divide nums into 2 partitions,
where num1 and num2 must locate in different partitions. 
"""