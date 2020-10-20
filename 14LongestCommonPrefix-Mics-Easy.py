class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        ans = strs[0]
        for i in range(1, len(strs)):
            newcomer = strs[i]
            newAns = ""
            for j in range(min(len(newcomer), len(ans))):
                if newcomer[j] == ans[j]:
                    newAns += ans[j]
                else:
                    break
            ans = newAns
            if len(ans) == 0:
                break
        return ans
    
"""
https://leetcode.com/problems/longest-common-prefix/
"""