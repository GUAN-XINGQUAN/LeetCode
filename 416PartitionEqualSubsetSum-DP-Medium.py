class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if s % 2 == 1:
            return False
        s = s // 2
        if s == 0:
            return True
        temp = [False for _ in range(s + 1)]
        dp = [list(temp) for _ in range(len(nums))]
        for idx in range(len(nums)):
            for curS in range(s + 1):
                if curS == 0:
                    dp[idx][curS] = True
                    continue
                if idx == 0:
                    if curS == nums[idx] or curS == 0:
                        dp[idx][curS] = True
                    else:
                        dp[idx][curS] = False
                else:
                    val = nums[idx]
                    if curS - val >= 0 and dp[idx - 1][curS - val]:
                        dp[idx][curS] = True
                    elif dp[idx - 1][curS]:
                        dp[idx][curS] = True
                    else:
                        dp[idx][curS] = False
                if curS == s and dp[idx][curS] == True:
                    return True
        return False       
        
"""
https://leetcode.com/problems/partition-equal-subset-sum/
Several questions to ask yourself before solving a DP problem
1. Is the question recursive? 
2. Is there any recursion parameter sets that emerge more than once ?
The 2 questions will help us decide whether or not to apply DP,
and how many dimensions the memory array need. 

In this case, there're 2 parameters - curIdx, and potential sum. 
"""