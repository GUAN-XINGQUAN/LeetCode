class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if not s:
            return False
        
        wordDict = set(wordDict)
        dp = [[False for _ in range(len(s))] for _ in range(len(s))]
        for l in range(1, len(s) + 1):
            for leftIdx in range(len(s) - l + 1):
                rightIdx = leftIdx + l - 1
                curWord = s[leftIdx:rightIdx + 1]
                if curWord in wordDict:
                    dp[leftIdx][rightIdx] = True
                elif l > 1:
                    for sepIdx in range(leftIdx + 1, rightIdx + 1):
                        if dp[leftIdx][sepIdx - 1] == True and dp[sepIdx][rightIdx] == True:
                            dp[leftIdx][rightIdx] = True
                            break
        return dp[0][len(s) - 1]
"""
https://leetcode.com/problems/word-break/
DP. 
"""