class Solution:
    def numDecodings(self, s: str) -> int:
        dp = [0 for _ in range(len(s))]
        dp[0] = 1 if s[0] != "0" else 0
        if dp[0] == 0:
            return 0
        for i in range(1, len(s)):
            char = s[i]
            if char == "0":
                if int(s[i - 1]) > 2 or int(s[i - 1]) == 0:
                    return 0
                else:
                    dp[i] = dp[i - 2] if i >= 2 else 1
            else:
                dp[i] = dp[i - 1] # single char as one alphabet
                if s[i - 1] != "0" and 0 < int(s[i - 1:i + 1]) <= 26:
                    dp[i] += dp[i - 2] if i >= 2 else 1
        return dp[-1]
"""
https://leetcode.com/problems/decode-ways/
DP. Unique Path. 
"""