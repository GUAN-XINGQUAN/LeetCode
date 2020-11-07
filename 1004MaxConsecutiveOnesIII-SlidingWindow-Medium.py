class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        leftIdx = 0
        maxLen = 0
        flips = set()
        for rightIdx in range(len(A)):
            rightVal = A[rightIdx]
            if rightVal == 0:
                flips.add(rightIdx)
            # Move left
            while len(flips) > K:
                if leftIdx in flips:
                    flips.remove(leftIdx)
                leftIdx += 1
                
            # Count
            maxLen = max(maxLen, rightIdx - leftIdx + 1)
        return maxLen
"""
https://leetcode.com/problems/max-consecutive-ones-iii/
A slinding window problem.
"""  