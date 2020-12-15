class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        maxes = [[0 for _ in range(len(arr))] for _ in range(len(arr))]
        dp = [[0 for _ in range(len(arr))] for _ in range(len(arr))]
        for i in range(len(arr)):
            for j in range(len(arr)):
                if i <= j:
                    maxes[i][j] = max(arr[i:j+1])
        for winSize in range(1, len(arr)):
            for leftIdx in range(len(arr) - winSize):
                rightIdx = leftIdx + winSize
                for sepIdx in range(leftIdx + 1, rightIdx + 1):
                    if dp[leftIdx][rightIdx] == 0:
                         dp[leftIdx][rightIdx] = dp[leftIdx][sepIdx - 1] + dp[sepIdx][rightIdx] + maxes[leftIdx][sepIdx - 1] * maxes[sepIdx][rightIdx]
                    else:
                        dp[leftIdx][rightIdx] = min(dp[leftIdx][rightIdx], 
                                                    dp[leftIdx][sepIdx - 1] + 
                                                    dp[sepIdx][rightIdx] + 
                                                    maxes[leftIdx][sepIdx - 1] * maxes[sepIdx][rightIdx])
        return dp[0][len(arr) - 1]
"""
https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
DP Merging intervals problem. 
"""