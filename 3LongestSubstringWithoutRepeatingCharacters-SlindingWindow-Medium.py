class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charCnt = dict()
        ans = 0
        dupCnt = 0
        leftIdx = 0
        for rightIdx in range(len(s)):
            rightChar = s[rightIdx]
            charCnt[rightChar] = charCnt.setdefault(rightChar, 0) + 1
            if charCnt[rightChar] > 1:
                dupCnt += 1
            while dupCnt > 0:
                leftChar = s[leftIdx]
                charCnt[leftChar] = charCnt[leftChar] - 1
                leftIdx += 1
                if charCnt[leftChar] > 0:
                    dupCnt -= 1
           # By this time, dupCnt == 0
            if rightIdx - leftIdx + 1 > ans:
                ans = rightIdx - leftIdx + 1
        return ans
    
"""
https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
Still a sliding window problem. Please refer to documents for more ideas in this topic. 
DupCnt is the left-moval indicator, representing the existing dups inside the window. 
If dup exist, left cursor needs to be moved. 
"""
       