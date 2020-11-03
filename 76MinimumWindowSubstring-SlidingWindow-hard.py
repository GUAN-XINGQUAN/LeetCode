class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ansLen = len(t)
        ans = s
        cnt = 0
        myDict = dict()
        for char in t:
            myDict[char] = myDict.setdefault(char, 0) + 1
        oriDict = dict(myDict)
        leftIdx = 0
                
        for rightIdx in range(len(s)):
            rightChar = s[rightIdx]
            myDict[rightChar] = myDict.setdefault(rightChar, 0) - 1
            if myDict[rightChar] >= 0 and myDict[rightChar] < oriDict[rightChar]:
                cnt += 1
                
            while rightIdx >= len(t) and leftIdx <= rightIdx and myDict[s[leftIdx]] < 0:
                # Judge if left pointer needs to move
                leftChar = s[leftIdx]
                myDict[leftChar] += 1
                leftIdx += 1
            if cnt == ansLen and len(ans) > rightIdx - leftIdx + 1:
                ans = s[leftIdx:rightIdx + 1]
        if cnt < ansLen:
            return ""
        return ans
    
"""
https://leetcode.com/problems/minimum-window-substring/submissions/

The problem is a classic sliding window problem. Please refer to this problem for more detailed explainations. 
438.Find All Anagrams in a String - https://leetcode.com/problems/find-all-anagrams-in-a-string/

Take care of the following points - 
1. cnt won't decrease. Once the first ans is found, cnt will remain len(t) and the window will always contain a potential answer.
2. leftIdx increases only when current char is redundant for current ans window. 
"""